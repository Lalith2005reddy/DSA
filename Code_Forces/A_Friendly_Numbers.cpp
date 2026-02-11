#include <iostream>
using namespace std;

int sum_digits(long long n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long x;
        cin >> x;
        int count = 0;
        for (int s = 0; s <= 100; s++) {
            long long y = x + s;
            if (sum_digits(y) == s) {
                count++;
            }
        }
        cout << count << "\n";
    }
    return 0;
}