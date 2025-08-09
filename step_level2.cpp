



#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

bool areAllDigitsPrime(int num) {
    while (num > 0) {
        int digit = num % 10;
        if (digit != 2 && digit != 3 && digit != 5 && digit != 7) {
            return false; 
        }
        num /= 10;
    }
    return true;
}
// Function to check if all digits in a number are unique
bool hasUniqueDigits(int num) {
    unordered_set<int> digits;
    while (num > 0) {
        int digit = num % 10;
        if (digits.find(digit) != digits.end()) {
            return false; // Duplicate digit found
        }
        digits.insert(digit);
        num /= 10;
    }
    return true;
}

int main() {

    // Level 1
    int n = 100; // Number of terms to generate
    vector<int> sequence;
    sequence.push_back(2); // Start the sequence with 2

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

    // Level 2
    vector<int> filteredSequence;
    int sum = 0;

    for (int term : sequence) {
        if (areAllDigitsPrime(term)) {
            filteredSequence.push_back(term);
            sum += term;
        }
    }

    cout << "Numbers with all prime digits: ";
    for (int term : filteredSequence) {
        cout << term << " ";
    }
    cout << endl;

    cout << "Count of numbers with all prime digits: " << filteredSequence.size() << endl;
    cout << "Sum of numbers with all prime digits: " << sum << endl;

    // Level 3: Sum of numbers with unique digits
    int uniqueDigitSum = 0;
    for (int term : sequence) {
        if (hasUniqueDigits(term)) {
            uniqueDigitSum += term;
        }
    }

    cout << "Sum of numbers with unique digits: " << uniqueDigitSum << endl;

    return 0;
}