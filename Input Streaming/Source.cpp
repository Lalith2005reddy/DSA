#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("input.txt");

    if (!file) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    int rows, cols;
    file >> rows >> cols; // Read matrix size

    int matrix[rows][cols];

    // Read matrix from file
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            file >> matrix[i][j];
        }
    }

    file.close(); // Close the file

    // Print matrix
    cout << "Matrix read from file:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
