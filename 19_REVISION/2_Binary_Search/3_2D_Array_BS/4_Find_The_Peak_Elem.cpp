#include<iostream>
using namespace std;
#include <bits/stdc++.h>





// bruteForece 
//TC O(M*N)
vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int Max_Ele = INT_MIN;
        int n = mat.size();
        int m = mat[0].size();
        int row = -1;
        int col = -1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] > Max_Ele){
                    Max_Ele = mat[i][j];
                    row =i;
                    col =j;
                }
            }
        }

        return {row,col};
    }



//Brute Force Better 
//TC O(M*N) Where we Check the all adjacent Sides of the Arrays


// Binary Approach
// TC O(LogM * N)
 int findTheMaxRowIndex(vector<vector<int>>& mat,int col) {
    int Max_Ele = INT_MIN;
    int n = mat.size();
    int row = 0;
    for (int i = 0; i < n; i++) {
            if (mat[i][col] > Max_Ele) {
                Max_Ele = mat[i][col];
                row = i;
            }
    }
    return row;
}
vector<int> findPeakGridBS(vector<vector<int>>& mat) { 
    int n = mat.size();
    int m = mat[0].size();
    int low = 0;
    int high = m-1;
    while(low <= high){
        int mid = low + ((high-low )/2);
        int MaxindexEleRow = findTheMaxRowIndex(mat,mid);
        int left = mid-1 >= 0 ? mat[MaxindexEleRow][mid-1] : -1;
        int right = mid+1 < m ?  mat[MaxindexEleRow][mid+1] : -1;
        if(left < mat[MaxindexEleRow][mid] && mat[MaxindexEleRow][mid] > right ){
            return {MaxindexEleRow , mid};
        }else if(left > mat[MaxindexEleRow][mid]) high = mid -1;
        else low = mid+1;
    }
    
    return {-1, -1};
    
}

int main(){


    vector<vector<int>> mat = {
        {10,20,15},
        {21,30,14},
        {7,16,32},
    };

    // vector<int> ans = findPeakGrid(mat);
    vector<int> ans = findPeakGridBS(mat);

    cout << ans[0] << "  " << ans[1];
return 0;
}