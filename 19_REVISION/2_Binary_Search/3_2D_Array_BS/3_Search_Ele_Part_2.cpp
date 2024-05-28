#include<iostream>
using namespace std;
#include <bits/stdc++.h>


int isElement(vector<int> arr, int n, int target) {
    int start = 0;
    int end = n - 1;
    while (start <= end) {
        int mid = start + ((end - start) / 2);
        if (arr[mid] == target) {
            return arr[mid];
        } else if (target > arr[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return -1;
}
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++) {
            int ans = isElement(matrix[i], m, target);
            if(ans == target) return true;
    }
    return false;
}

// Binary Search Optimal

// TC O(m+n)

bool searchMatrixOptimal(vector<vector<int>>& matrix, int target) {

        int n = matrix.size();
        int m = matrix[0].size();
        int row = 0, col = m - 1;

        // traverse the matrix from (0, m-1):
        while (row < n && col >= 0) {
            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] < target)
                row++;
            else
                col--;
        }
        return false;
    }

int main(){



    vector<vector<int>> matrix = 
    {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    // cout << searchMatrix(matrix, 8);
    cout << searchMatrixOptimal(matrix, 8);
return 0;
}