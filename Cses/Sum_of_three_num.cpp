#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long val;
    cin >> n >> val;

    vector<pair<long long, int>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i + 1; // original index
    }

    sort(arr.begin(), arr.end()); // sort by value

    for (int i = 0; i < n; i++) {
        long long diff = val - arr[i].first;
        int l = i + 1, r = n - 1;

        while (l < r) {
            long long sum = arr[l].first + arr[r].first;
            if (sum == diff) {
                vector<int> ans = {arr[i].second, arr[l].second, arr[r].second};
                sort(ans.begin(), ans.end()); // sort the indices before printing
                cout << ans[0] << " " << ans[1] << " " << ans[2];
                return 0;
            } else if (sum < diff) {
                l++;
            } else {
                r--;
            }
        }
    }

    cout << "IMPOSSIBLE";
    return 0;
}
