#include <iostream>

using namespace std;

int main() {
    freopen("sample_input.txt", "r", stdin); // Redirect input from file to cin

    int N;
    cin >> N;  // Read number of test cases

    for (int i = 0; i < N; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;  // Read four numbers directly

        if (a == b && b == c && c == d) {
            cout << "Square" << endl;
        } else if (a == c && b == d) {
            cout << "Rectangle" << endl;
        } else {
            cout << "Quadrilateral" << endl;
        }
    }

    return 0;
}
