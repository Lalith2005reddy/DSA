# #!/usr/bin/env python
# # -*- coding: utf-8 -*-
# """
# Compare AdaScale vs. standard min/max quantization on Llama-3 3B:
#   • Embedding 16-bit
#   • Decoder weights 4-bit
#   • LM-head 8-bit (if untied)
#   • Activations 16-bit
#   • No AdaScale, just min/max PTQ
# """

# import os, time, torch, pandas as pd
# from torch.utils.data import Dataset, DataLoader
# from transformers import AutoTokenizer, AutoModelForCausalLM
# from datasets import load_dataset
# from aimet_torch import QuantizationSimModel

# device = torch.device("cuda" if torch.cuda.is_available() else "cpu")

# class DummyDataset(Dataset):
#     def __init__(self, tokenizer, texts):
#         self.tokenizer, self.texts = tokenizer, texts
#     def __len__(self):  return len(self.texts)
#     def __getitem__(self, idx):
#         enc = self.tokenizer(
#             self.texts[idx],
#             return_tensors="pt",
#             padding="max_length",
#             truncation=True,
#             max_length=512,
#         )
#         enc.pop("token_type_ids", None)
#         return {k: v.squeeze(0).to(device) for k, v in enc.items()}

# @torch.no_grad()
# def calculate_perplexity(model, encodings, seq_len=512):
#     ids     = encodings.input_ids.to(device)
#     n_steps = ids.numel() // seq_len
#     losses  = []
#     model.eval()
#     loss_fct = torch.nn.CrossEntropyLoss(reduction="none")
#     for i in range(n_steps):
#         block = ids[:, i*seq_len:(i+1)*seq_len]
#         if block.size(1) < 2: continue
#         out = model(block)
#         lm_logits = out[0] if isinstance(out, tuple) else out.logits
#         shift_logits = lm_logits[:, :-1].contiguous()
#         shift_labels = block[:, 1:].contiguous()
#         loss = loss_fct(
#             shift_logits.view(-1, shift_logits.size(-1)),
#             shift_labels.view(-1)
#         )
#         losses.append(loss.mean() * shift_labels.size(1))
#     return float(torch.exp(torch.stack(losses).sum() / (n_steps * seq_len)))

# def set_mixed_precision(sim):
#     # Embedding = 16-bit
#     if hasattr(sim.model.model, "embed_tokens"):
#         sim.model.model.embed_tokens.param_quantizers["weight"].bitwidth = 16
#     # Decoder = 4-bit
#     for layer in sim.model.model.layers:
#         for proj in ("q_proj","k_proj","v_proj","o_proj"):
#             getattr(layer.self_attn, proj).param_quantizers["weight"].bitwidth = 4
#         for proj in ("gate_proj","up_proj","down_proj"):
#             getattr(layer.mlp, proj).param_quantizers["weight"].bitwidth = 4
#     # LM-head = 8-bit if untied
#     tied = getattr(sim.model.config, "tie_word_embeddings", False)
#     if not tied and hasattr(sim.model, "lm_head"):
#         sim.model.lm_head.param_quantizers["weight"].bitwidth = 8

# def main():
#     model_path = "fp32_language_model_by_sr"
#     tokenizer  = AutoTokenizer.from_pretrained(model_path)
#     # ensure pad_token
#     tokenizer.pad_token = tokenizer.pad_token or tokenizer.eos_token
#     # load model
#     model = AutoModelForCausalLM.from_pretrained(model_path).to(device)
#     model.eval(); model.config.return_dict = False
#     model.config.pad_token_id = tokenizer.pad_token_id

#     # prepare data
#     test_ds  = load_dataset("wikitext","wikitext-2-raw-v1",split="test")
#     test_enc = tokenizer("\n\n".join(test_ds["text"]), return_tensors="pt")
#     # simple filtering
#     def is_good(s): return bool(s.strip()) and "." in s and len(s.split())>10
#     calib_texts = [t for t in test_ds["text"] if is_good(t)][:100]
#     calib_set    = DummyDataset(tokenizer, calib_texts)
#     calib_loader = DataLoader(calib_set, batch_size=8)

#     # FP32 perplexity
#     t0 = time.time()
#     fp32_ppl = calculate_perplexity(model, test_enc)
#     print(f"FP32 PPL    : {fp32_ppl:.2f} (took {time.time()-t0:.1f}s)")

#     # Build QuantSim for min/max PTQ
#     dummy = tokenizer(calib_texts[0], return_tensors="pt")["input_ids"].to(device)
#     sim   = QuantizationSimModel(
#         model=model,
#         dummy_input=dummy,
#         default_output_bw=16,
#         default_param_bw=4
#     )
#     sim.model = sim.model.to(device)

#     # Apply mixed precision settings
#     set_mixed_precision(sim)

#     # Compute min/max encodings
#     sim.compute_encodings(lambda m, dl: [m(**b) for b in dl[0]], (calib_loader,))
#     # Save if desired
#     os.makedirs("minmax_encodings", exist_ok=True)
#     sim.save_encodings_to_json("minmax_encodings", filename_prefix="enc")

#     # Quantized perplexity
#     t1 = time.time()
#     quant_ppl = calculate_perplexity(sim.model, test_enc)
#     print(f"Min/max PPL : {quant_ppl:.2f} (took {time.time()-t1:.1f}s)")

#     # Log
#     pd.DataFrame({
#         "Mode":["fp32","minmax"],
#         "Perplexity":[fp32_ppl, quant_ppl]
#     }).to_csv("minmax_vs_fp32_ppl.csv", index=False)
#     print("Results saved → minmax_vs_fp32_ppl.csv")

# if __name__=="__main__":
#     main()


#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
Quantize Llama-3 3 B model with AdaScale:
  • Embedding 16-bit
  • Decoder weights 4-bit
  • LM-head 8-bit (only if not weight-tied)
  • Activations 16-bit
"""

import os, time, torch, pandas as pd
from torch.utils.data import Dataset, DataLoader
from transformers import AutoTokenizer, AutoModelForCausalLM
from datasets import load_dataset
from aimet_torch import QuantizationSimModel
from adascale_optimizer import apply_adascale                  # optimizer code you supplied

device = torch.device("cuda" if torch.cuda.is_available() else "cpu")

# --------------------------------------------------------------------------- #
# 1. DATASET WRAPPER
# --------------------------------------------------------------------------- #
class DummyDataset(Dataset):
    def __init__(self, tokenizer, texts):
        self.tokenizer, self.texts = tokenizer, texts

    def __len__(self):  return len(self.texts)

    def __getitem__(self, idx):
        enc = self.tokenizer(
            self.texts[idx],
            return_tensors="pt",
            padding="max_length",
            truncation=True,
            max_length=512,
        )
        enc.pop("token_type_ids", None)
        return {k: v.squeeze(0).to(device) for k, v in enc.items()}

# --------------------------------------------------------------------------- #
# 2. HELPER FUNCTIONS
# --------------------------------------------------------------------------- #
def forward_fn(model, batch):
    if isinstance(batch, tuple):
        return model(*batch)
    if isinstance(batch, dict):
        return model(**batch)
    raise TypeError("Unsupported batch type")

def forward_pass_callback(model, loaders):
    for batch in loaders[0]:
        forward_fn(model, batch)

def is_good_sample(sample):
    text = sample["text"].strip()
    if not text:                                                  return False
    if "." in text and len(text.split()) > 10:                    return True
    lines = text.split("\n")
    if len(lines) > 1 and all(len(l.split()) < 5 for l in lines): return False
    if text.startswith("==") and text.endswith("=="):             return False
    if len(text) < 20:                                            return False
    if (text.count("=") + text.count("@") + text.count("-")) / len(text) > 0.5:
        return False
    return True

@torch.no_grad()
def calculate_perplexity(model, encodings, seq_len=512):
    """Sliding-window perplexity (next-token prediction)."""
    ids     = encodings.input_ids.to(device)
    n_steps = ids.numel() // seq_len
    losses  = []
    model.eval()

    ce_loss = torch.nn.CrossEntropyLoss(reduction="none")
    for i in range(n_steps):
        block = ids[:, i * seq_len : (i + 1) * seq_len]
        if block.size(1) < 2: continue
        logits = model(block)[0] if isinstance(model(block), tuple) else model(block).logits
        shift_logits = logits[:, :-1].contiguous()
        shift_labels = block[:, 1:].contiguous()
        loss = ce_loss(shift_logits.view(-1, shift_logits.size(-1)),
                       shift_labels.view(-1))
        losses.append(loss.mean() * shift_labels.size(1))

    return float(torch.exp(torch.stack(losses).sum() / (n_steps * seq_len)))

# --------------------------------------------------------------------------- #
# 3. QUANTIZATION HELPERS
# --------------------------------------------------------------------------- #
def set_custom_bitwidths(sim):
    """Embedding=16, Decoder=4, LM-head=8 (if untied)."""
    # Embedding
    if hasattr(sim.model.model, "embed_tokens"):
        sim.model.model.embed_tokens.param_quantizers["weight"].bitwidth = 16

    # Decoder layers
    for layer in sim.model.model.layers:
        # Self-attention projections
        for proj in ("q_proj", "k_proj", "v_proj", "o_proj"):
            getattr(layer.self_attn, proj).param_quantizers["weight"].bitwidth = 4
        # MLP projections
        for proj in ("gate_proj", "up_proj", "down_proj"):
            getattr(layer.mlp, proj).param_quantizers["weight"].bitwidth = 4

    # LM head (only if it has separate weights)
    tied = getattr(sim.model.config, "tie_word_embeddings", True)
    if not tied and hasattr(sim.model, "lm_head"):
        sim.model.lm_head.param_quantizers["weight"].bitwidth = 8

def verify_config(sim):
    print("\n=== Bit-width verification ===")
    print("Embedding :", sim.model.model.embed_tokens.param_quantizers["weight"].bitwidth)
    print("Layer-0 q_proj:", sim.model.model.layers[0].self_attn.q_proj.param_quantizers["weight"].bitwidth)
    lm_bw = "tied" if getattr(sim.model.config, "tie_word_embeddings", True) else \
             sim.model.lm_head.param_quantizers["weight"].bitwidth
    print("LM-head  :", lm_bw, "\n")

# --------------------------------------------------------------------------- #
# 4. MAIN PIPELINE
# --------------------------------------------------------------------------- #
def main():
    model_path = "fp32_language_model_by_sr"          # local or HF hub path
    tokenizer   = AutoTokenizer.from_pretrained(model_path)
    model       = AutoModelForCausalLM.from_pretrained(model_path).to(device)
    model.eval(); model.config.return_dict = False

    # --- Prepare calibration + evaluation data ----------------------------- #
    test_ds  = load_dataset("wikitext", "wikitext-2-raw-v1", split="test")
    test_enc = tokenizer("\n\n".join(test_ds["text"]), return_tensors="pt")

    calib_texts = [t for t in test_ds.filter(is_good_sample)["text"][:100]]
    calib_set   = DummyDataset(tokenizer, calib_texts)
    calib_loader= DataLoader(calib_set, batch_size=8)

    # --- Build QuantizationSimModel --------------------------------------- #
    dummy = tokenizer(calib_texts[0], return_tensors="pt")["input_ids"].to(device)
    sim   = QuantizationSimModel(model, dummy_input=dummy,
                                 default_output_bw=16, default_param_bw=4)  # W4-A16

    # --- AdaScale optimization -------------------------------------------- #
    t0 = time.time()
    apply_adascale(sim, calib_loader, forward_fn=forward_fn, num_iterations=50)
    print(f"AdaScale finished in {time.time()-t0:.1f} s")

    # --- Custom bit-widths + verify --------------------------------------- #
    set_custom_bitwidths(sim)
    verify_config(sim)

    # --- Compute encodings ------------------------------------------------- #
    sim.compute_encodings(forward_pass_callback, (calib_loader,))
    sim.save_encodings_to_json("./encod_test", filename_prefix="encodings")

    # --- Perplexity comparison -------------------------------------------- #
    ppl_fp32  = calculate_perplexity(model, test_enc)
    ppl_quant = calculate_perplexity(sim.model, test_enc)

    print(f"FP32  perplexity : {ppl_fp32:.2f}")
    print(f"W4A16 perplexity : {ppl_quant:.2f}")

    # --- Optional CSV logging --------------------------------------------- #
    pd.DataFrame({
        "PPL_FP32":[ppl_fp32],
        "PPL_Quant":[ppl_quant]
    }).to_csv("results_log.csv", index=False)
    print("Logged results → results_log.csv")

if __name__ == "__main__":
    main()