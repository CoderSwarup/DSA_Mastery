#include<iostream>
using namespace std;
#include <bits/stdc++.h>


vector<vector<int>> rotateBruteForce(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    // create a ans array
    vector<vector<int>> ans(n,vector<int>(m));


    // here is patter that followi // let assume the matrix size 4*4
    // i   j      j n-1-i
    // [0][0] => [0][3]
    // [0][1] => [1][3]
    // [0][2] => [2][3]
    // [0][3] => [3][3]

    for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        ans[j][n-1-i] = matrix[i][j];
        }
    }

     return ans;


}


// OPTIMAL

vector<vector<int>> rotateOptimal(vector<vector<int>> &matrix){
    int n = matrix.size();



    
      for (int i = 0; i < n - 1; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

    // now reverse the 
    for (int i = 0; i < n; i++) {
        int s = 0;
        int e = n - 1;
        while (s < e) {
            swap(matrix[i][s], matrix[i][e]);
            s++;
            e--;
        }
    }

    // also 
    // for (int i = 0; i < n; i++) {
    //     reverse(matrix[i].begin(),matrix[i].end());
    // }





    return matrix;
}

int main(){

    vector < vector < int >> arr =  {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // vector < vector < int >> rotated = rotateBruteForce(arr);
    vector < vector < int >> rotated = rotateOptimal(arr);
    for (int i = 0; i < rotated.size(); i++) {
    for (int j = 0; j < rotated[0].size(); j++) {
        cout << rotated[i][j] << " ";
    }
    cout << endl;
    }

return 0;
}