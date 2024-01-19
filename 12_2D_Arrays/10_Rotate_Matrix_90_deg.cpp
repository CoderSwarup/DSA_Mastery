#include<iostream>
#include<vector>

using namespace std;

void printArray(vector<vector<int>> matrix){
    int n = matrix.size();
    int m = matrix[0].size();


     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << matrix[i][j] << " ";

        }

        cout << endl;

    }

}


// Time Complexity O(n^2)
// Space Complexity O(m*n) 
vector<vector<int>> Rotate(vector<vector<int>> matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans(m,vector<int>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans[j][n-i-1] = matrix[i][j];

        }

    }

    return ans;
}


// Optimal // but here is condition is n*m is same 
// Time Complexity O(n^2)
// Space Complexity O(1) 
void RotateOptimal(vector<vector<int>> &matrix){
    int n = matrix.size();

    // transpose 
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
           swap(matrix[i][j],matrix[j][i]);
        }
    }

    // revese row
    for(int i=0;i<n;i++){
        int s =0;
        int e = n-1;
        while(s<e){
            swap(matrix[i][s],matrix[i][e]);
            s++;
            e--;
        }
    }

}



int main() {
    vector<vector<int>> matrix = {{1, 2, 3,4}, { 5, 6,7,8}, {9,10,11,12},{13,14,15,16}};
    // vector<vector<int>> ans = Rotate(matrix);
    // printArray(ans);
   vector<vector<int>> matrix2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};


    
    printArray(matrix2);
    RotateOptimal(matrix2);
    printArray(matrix2);
    return 0;
}
