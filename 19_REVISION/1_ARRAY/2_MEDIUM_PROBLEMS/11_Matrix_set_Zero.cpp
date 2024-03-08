#include<iostream>
using namespace std;
#include <bits/stdc++.h>


// brute force 
// TC O(M*N) + O(M+N) + O(M*N) ==> O(N3) near

// set row to -1
void setRow(vector<vector<int>> &matrix,int n, int m, int row){

    for(int i=0;i<m;i++){
        if(matrix[row][i] != 0 ){
            matrix[row][i] = -1;
        }
    }

}
void setCol(vector<vector<int>> &matrix,int n, int m, int col){

    for(int i=0;i<n;i++){
        if(matrix[i][col] != 0 ){
            matrix[i][col] = -1;
        }
    }

}

vector<vector<int>> zeroMatrixBruteForce(vector<vector<int>> &matrix, int n, int m) {

    // 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j] == 0){
                    setRow(matrix,n,m,i);
                    setCol(matrix,n,m,j);
            }
        }
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j] != 1){
                   matrix[i][j] = 0; 
            }
        }
    }



    return  matrix;
}


// Better
// TC O(N*M ) + O(M*N) => 2(N*M)
// SC O(N+M)

vector<vector<int>> zeroMatrixBetter(vector<vector<int>> &matrix, int n, int m) {

    vector<int>rowMark(n,0);
    vector<int>colMark(m,0);

    // 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j] == 0){
                    rowMark[i] = 1;
                    colMark[j] = 1;
            }
        }
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(rowMark[i] == 1 || colMark[j] == 1){
                   matrix[i][j] = 0; 
            }
        }
    }



    return  matrix;
}


// OPTIMAL  without using extra space

// TC O(N*M ) + O(M*N) => 2(N*M)
// SC O(N+M)

vector<vector<int>> zeroMatrixOptimal(vector<vector<int>> &matrix, int n, int m) {

    // vector<int>rowMark(n,0); ==> matrix[...][0]   ⬇️
    // vector<int>colMark(m,0); ==>  matrix[0][...]  ➡️

    int col =1;
    

    // 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j] == 0){
                   // set row jth element to 0
                   matrix[i][0] = 0;
                   // check j !== 0 
                   if(j != 0)
                   matrix[0][j] = 0;
                   else
                   col =0;

            }
        }
    }

    // try to solve all matrix element 0th col , row 
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(matrix[i][j] !=0){
                  if(matrix[i][0] == 0 || matrix[0][j] ==0){
                    matrix[i][j] = 0;
                  }
            }
        }
    }

    // if matrix 1st col & then 1st row:
      if (matrix[0][0] == 0) {
        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }

    if(col ==0){
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }



    return  matrix;
}




int main(){

    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();
    // vector<vector<int>> ans = zeroMatrixBruteForce(matrix, n, m);
    // vector<vector<int>> ans = zeroMatrixBetter(matrix, n, m);
    vector<vector<int>> ans = zeroMatrixOptimal(matrix, n, m);

    cout << "The Final matrix is: \n";
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }

    return 0;
}