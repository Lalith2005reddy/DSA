#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;

    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        // Option 1: buy separately
        ll o = (ll)cost1 * need1 + (ll)cost2 * need2;

        // Option 2: buy combined items
        ll p = (ll)costBoth * max(need1, need2);

        // Return minimum cost
        return min(o, p);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt","r",stdin);
    int t;
    cin >> t;

    Solution sol;

    while (t--) {
        int cost1, cost2, costBoth, need1, need2;
        cin >> cost1 >> cost2 >> costBoth >> need1 >> need2;

        cout << sol.minimumCost(cost1, cost2, costBoth, need1, need2) << "\n";
    }

    return 0;
}
