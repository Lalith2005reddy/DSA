#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {

    //Level 1
    int n = 100; // Number of terms to generate
    vector<int> sequence;
    sequence.push_back(2); 

    int current = 3; 
    while (sequence.size() < n) {
        if (isPrime(current)) {
            sequence.push_back(sequence.back() + current);
        }
        current++;
    }

    cout << "First " << n << " terms of the sequence are: ";
    for (int term : sequence) {
        cout << term << " ";
    }
    cout << endl;

    //Level 2 : From that list,display only those numbers whose all digits are prime digits (i.r 23 (2 and 3 are prime digits), 37 (3 and 7 are prime digits) etc.) Display the count and sum of the series

    return 0;
}