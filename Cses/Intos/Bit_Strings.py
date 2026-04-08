"""MOD = 10**9+7

n = int(input())
print(pow(2,n,MOD)) """

MOD = 10**9+7

n = int(input())


ans = 1
for _ in range(n):
    ans = (ans * 2) % MOD

print(ans)
