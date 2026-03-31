#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    // Construct the permutation: [2, n, n-1, ..., 3, 1]
    cout << 2 << " "; // The first element is 2
    for (int i = n; i >= 3; --i) {
        cout << i << " "; // Elements from n down to 3
    }
    cout << 1 << endl; // The last element is 1
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}