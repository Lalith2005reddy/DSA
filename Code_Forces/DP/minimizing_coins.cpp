#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int mod = 1e9+7;
vector<int> dp(1000001, -1);  // memoization

int minCoins(int sum, vector<int> &coins) {
    if (sum == 0) return 0;         // 0 coins needed for sum 0
    if (sum < 0) return INT_MAX;    // invalid path
    if (dp[sum] != -1) return dp[sum];

    int minC = INT_MAX;
    for (int c : coins) {
        int sub = minCoins(sum - c, coins);
        if (sub != INT_MAX) {
            minC = min(minC, sub + 1);
        }
    }
    return dp[sum] = minC;
}

int main() {
    int n, sum;
    cin >> n >> sum;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    int res = minCoins(sum, coins);
    if (res == INT_MAX) cout << -1 << endl;
    else cout << res << endl;
}
