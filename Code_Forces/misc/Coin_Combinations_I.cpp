#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int n, x;
vector<int> a;
vector<int> memo;

// top-down DP function
int ways(int sum) {
    // base cases
    if (sum == 0) return 1;
    if (sum < 0) return 0;

    // already computed
    if (memo[sum] != -1) return memo[sum];

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans = (ans + ways(sum - a[i])) % MOD;
    }

    return memo[sum] = ans;
}

int main() {
    cin >> n >> x;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // initialize memo with -1 (uncomputed)
    memo.assign(x + 1, -1);

    cout << ways(x) << endl;
    return 0;
}
