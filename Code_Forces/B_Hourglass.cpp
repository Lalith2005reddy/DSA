#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long s, k, m;
        cin >> s >> k >> m;

        long long cycle = min(s, k);
        long long elapsed = m % k;

        long long remaining = cycle - elapsed;
        if (remaining < 0) remaining = 0;

        cout << remaining << '\n';
    }
    return 0;
}
