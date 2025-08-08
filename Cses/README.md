# AdaScale Quantization for Llama Models

This repository contains code to perform post-training quantization (PTQ) of Llama and similar transformer models using the **AdaScale** technique — a blockwise knowledge distillation approach with learnable scale parameters, based on FlexRound and Omniquant methods.  

We provide driver scripts, quantizers, optimizer code, and configuration for mixed-precision quantization of decoder-only LLMs. The repository also includes a baseline min-max quantization script for comparison.

---

## Repository Structure

| File                   | Description                                                                                                          |
|------------------------|----------------------------------------------------------------------------------------------------------------------|
| `adascale_optimizer.py`| Main AdaScale optimizer implementation applying blockwise PTQ with learnable scales (customized from Qualcomm AIMET).|
| `adascale_quantizer.py`| Defines AdaScale quantizer classes used during optimization with learnable parameters `beta`, `gamma`, `s2`, `s3`, `s4`.|
| `driver_code.py`       | Example driver showing how to wrap a Llama model with AIMET quant sim, run AdaScale optimization, and compute PPL.   |
| `min_max_quant.py`     | Baseline script performing standard min-max quantization using AIMET for comparison against AdaScale.                |
| `qsim_PCQ_config.json` | QuantizationSimModel configuration enabling per-channel quantization, mixed precision, and operator-specific settings.|

---

## AdaScale Overview

AdaScale is a post-training quantization technique that performs blockwise knowledge distillation between the FP32 and quantized model blocks. It introduces learnable scale parameters (`beta`, `gamma`, and other scale vectors `s2`, `s3`, `s4`) inside quantizers of supported layers (currently `Linear` and `Conv2d`). The optimizer trains these scales by minimizing the output MSE between FP32 and quantized blocks.

This approach builds on ideas from [FlexRound](https://arxiv.org/abs/2306.00317) and incorporates LWC (Learnable Weight Clipping) from Omniquant.

---

## Key Modifications in This Repository

- **Local `blockwise_sampler` copy:**  
  To fix import issues and ensure stable dependency management, the `blockwise_sampler` module from AIMET is copied and adapted locally.

- **GPU-Optimized Sampling:**  
  The model is moved to GPU (`cuda`) instead of CPU during optimization to accelerate blockwise caching and parameter tuning.

- **Input/Output Argument Adjustments:**  
  The optimizer carefully transforms block inputs and outputs by extracting only the relevant tensor components, removing extra dynamic cache objects for compatibility with Llama-like models.

- **Flexible Mixed Precision Setup:**  
  Via config and driver adjustments, embeddings are quantized at 16-bit, decoders at 4-bit, and LM head at 8-bit, allowing high accuracy at low precision.

- **Extensive Debug/Commenting:**  
  Included comments and commented-out code addressing attention mask duplications and input handling for further developer clarity.

---

## Getting Started

### Prerequisites

- Python 3.8+
- PyTorch (compatible CUDA version recommended)
- [transformers](https://huggingface.co/docs/transformers/)
- [datasets](https://huggingface.co/docs/datasets/)
- [aimet_torch](https://github.com/quic/aimet)
- `tqdm`, `pandas`

Install dependencies via pip:
'pip install torch transformers datasets tqdm pandas aimet_torch'


### Clone and Setup
git clone <your-repo-url>
cd <repo-folder>


---

## Usage

### 1. Run AdaScale quantization and evaluation
python driver_code.py

This script will:
- Load your FP32 Llama model
- Prepare dataset and dataloader for calibration
- Wrap the model with AIMET's `QuantizationSimModel` using `qsim_PCQ_config.json`
- Apply AdaScale blockwise tuning (`apply_adascale`) for 1000 iterations
- Compute and save quantization encodings
- Evaluate FP32 and quantized model perplexity (PPL) on the test set
- Output timing and PPL comparisons

---

### 2. Run standard Min-Max quantization baseline for comparison
python min_max_quant.py

This performs:
- Similar setup & dataset
- Standard min-max quantization using AIMET's encoding calibration
- Saves encodings independently in `./min_max_encodings`
- Computes and reports perplexity for FP32 and min-max quantized models

---

## `qsim_PCQ_config.json` Details

- Enables **per-channel quantization** for `Gemm` (linear) and `Conv` ops for improved accuracy.
- Default bitwidths and symmetric quantization settings tailored for hardware version `V79`.
- Mixed precision supplied programmatically (embeddings 16-bit, decoders 4-bit, LM head 8-bit).
- Biases remain in FP32 for numerical stability.
- Output quantization disabled for many non-parametric ops (reshape, squeeze, maxpool etc.) to avoid artifacts.
- Defines supergroups for fused ops to improve quantizer consistency during deployment.

---

## Code Overview

### `adascale_optimizer.py`

- Implements AdaScale algorithm:
  - Identifies blocks in the model to optimize.
  - Substitutes quantizers with AdaScale variants containing trainable parameters.
  - Runs blockwise sampler and optimizer steps with MSE loss.
  - Folds learnable scales back into weights after tuning.
- Customizations applied for compatibility with Llama model outputs and GPU usage.

### `adascale_quantizer.py`

- Defines AdaScale quantizer classes with learnable parameters:
  - `AdaScaleQuantizeDequantize`: Base class with `beta`, `gamma`.
  - `AdaScaleLinearQuantizeDequantize`: Extends for linear layers, adds `s2`, `s3`.
  - `AdaScaleConv2dQuantizeDequantize`: Adds `s4` for conv2d layers.
- Supports parameter extraction, folding, and switching back to standard quantization objects.

### `driver_code.py`

- Loads tokenizer, model, and dataset.
- Constructs dummy dataset and dataloader.
- Wraps model with quant sim and applies AdaScale quantization.
- Evaluates perplexity before and after quantization.
- Saves encodings for deployment.

### `min_max_quant.py`

- Baseline min-max quantization flow on the same model and dataset.
- Computes standard encoding/calibration without trainable scale tuning.
- Allows direct perplexity and timing comparison.

---

## Usage Tips & Notes

- Adjust `num_iterations` in `apply_adascale` to tradeoff between compute and quantization quality.
- Modify dataset paths and model loading locations according to your setup.
- Consider GPU memory when tuning mixed precision and cache settings.
- This repository targets decoder-only transformer models; modifications may be needed for encoder-decoder or other architectures.

---

## References & Acknowledgments

- [Qualcomm AIMET](https://github.com/quic/aimet) for quantization infrastructure
- [FlexRound Paper](https://arxiv.org/abs/2306.00317)
- Omniquant for Learnable Weight Clipping (LWC) techniques
- HuggingFace transformers and datasets libraries
- Open-source Llama and related model implementations

---

## Contact

For questions or contributions, please open an issue or pull request in this repository.

---

Thank you for using and contributing to this AdaScale quantization toolkit!
