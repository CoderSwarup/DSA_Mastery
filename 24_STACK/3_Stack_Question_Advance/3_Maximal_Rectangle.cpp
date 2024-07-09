#include<iostream>
using namespace std;

#include <bits/stdc++.h>

int largestRectangleAreaM2(vector<int>& heights) {
    int n = heights.size();
    // stack
    stack<int> s;
    int ans = INT_MIN;
    int index;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && heights[s.top()] > heights[i]) {
            index = s.top();
            s.pop();
            if (!s.empty()) {
                ans = max(ans, heights[index] * (i - s.top() - 1));
            } else {
                ans = max(ans, heights[index] * i);
            }
        }
        s.push(i);
    }
    while (!s.empty()) {
        index = s.top();
        s.pop();
        if (!s.empty()) {
            ans = max(ans, heights[index] * (n - s.top() - 1));
        } else {
            ans = max(ans, heights[index] * n);
        }
    }
    return ans;
}
int maximalRectangle(vector<vector<char>>& matrix) {
    int ans = 0;
    int row = matrix.size();
    int col = matrix[0].size();
    vector<int> heights(col, 0);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] == '0') {
                heights[j] = 0;
            } else {
                heights[j]++;
            }
        }
        ans = max(ans, largestRectangleAreaM2(heights));
    }
    return ans;
}


int main(){

    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };

    cout << maximalRectangle(matrix);

return 0;
}