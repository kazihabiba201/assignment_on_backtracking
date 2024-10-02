//task2
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Function to check if the rat can move to the given cell
bool isSafe(int x, int y, const vector<vector<int>>& m, const vector<vector<bool>>& visited, int N) {
    return (x >= 0 && x < N && y >= 0 && y < N && m[x][y] == 1 && !visited[x][y]);
}

// Backtracking function to find the path
bool findPath(int x, int y, const vector<vector<int>>& m, vector<vector<bool>>& visited, int N) {
    // Base case: if we reach the destination
    if (x == N - 1 && y == N - 1) {
        return true;
    }

    // Mark this cell as visited
    visited[x][y] = true;

    // Move Down
    if (isSafe(x + 1, y, m, visited, N) && findPath(x + 1, y, m, visited, N)) return true;
    // Move Right
    if (isSafe(x, y + 1, m, visited, N) && findPath(x, y + 1, m, visited, N)) return true;
    // Move Up
    if (isSafe(x - 1, y, m, visited, N) && findPath(x - 1, y, m, visited, N)) return true;
    // Move Left
    if (isSafe(x, y - 1, m, visited, N) && findPath(x, y - 1, m, visited, N)) return true;

    // Unmark this cell as part of the path (backtracking)
    visited[x][y] = false;
    return false;
}

// Main function to determine if the rat can reach the destination
bool canRatReachDestination(const vector<vector<int>>& m, int N) {
    if (m[0][0] == 0 || m[N-1][N-1] == 0) return false;  // Check if starting or ending cell is blocked
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    return findPath(0, 0, m, visited, N);
}

// Helper function to parse matrix input from string
vector<vector<int>> parseMatrixInput(const string& input, int N) {
    vector<vector<int>> matrix(N, vector<int>(N));
    stringstream ss(input);
    char ch;
    int value, row = 0, col = 0;

    // Read input character by character
    while (ss >> ch) {
        if (isdigit(ch)) {
            ss.putback(ch);
            ss >> value;
            matrix[row][col] = value;
            col++;
            if (col == N) {
                row++;
                col = 0;
            }
        }
    }
    return matrix;
}

int main() {
    int N;
    string matrixInput;

    // Input matrix size
    cout << "Input (N): ";
    cin >> N;
    cin.ignore(); // Ignore the newline character after N input

    // Input matrix values in a formatted string
    cout << "m {{}, {}}:" << endl;
    getline(cin, matrixInput);

    // Parse matrix input string
    vector<vector<int>> m = parseMatrixInput(matrixInput, N);

    // Check if the rat can reach the destination
    if (canRatReachDestination(m, N)) {
        cout << "Output: true" << endl;
    } else {
        cout << "Output: false" << endl;
    }

    return 0;
}
//Time complexity: O(N^2)
//Space complexity: O(N^2)
