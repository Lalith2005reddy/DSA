#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minStepsMemo(int n, vector<int>& memo) {
    if (n == 0) return 0;
    if (memo[n] != -1) return memo[n];

    int minSteps = INT_MAX;
    int temp = n;
    while (temp > 0) {
        int digit = temp % 10;
        temp /= 10;
        if (digit == 0) continue;
        minSteps = min(minSteps, 1 + minStepsMemo(n - digit, memo));
    }

    memo[n] = minSteps;
    return minSteps;
}

int main() {
    int n;
    cin >> n;
    vector<int> memo(n + 1, -1);
    cout << minStepsMemo(n, memo) << endl;
    return 0;
}
