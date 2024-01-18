#include<iostream>
#include<vector>

using namespace std;

void Transpose(vector<vector<int>> &matrix) {
    int row = matrix.size();
    int col = matrix[0].size();

    for (int i = 0; i < row-1; i++) {
        for (int j = i + 1; j < col; j++) {
            // Swap elements matrix[i][j] and matrix[j][i]
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Print the transposed matrix
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {12, 34, 5}};
    Transpose(matrix);

    return 0;
}
