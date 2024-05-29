#include<iostream>
using namespace std;
#include <bits/stdc++.h>


// Time Complexityt

// O(1e9) + O(log(1e9) * N * Log(M))
int NumberofElementsLesserMid(vector<int> mat, int ele){
  
    int low =0;
    int high = mat.size()-1;
    
    while(low <=high){
        int mid = low + ((high-low)/2);
        if(mat[mid] > ele){
            high = mid-1;
        }else{
            low= mid+1;
        }
    }
    
    return low;
}
int medianBS(vector<vector<int>> &matrix){
    // code here
    int n = matrix.size();
    int m = matrix[0].size();
    
    int low =0;
    int high = 1e9;
    
    // also here we ge the max and min element of the array
    
    while(low <= high){
        int mid = low + ((high-low)/2);
        int ctn = 0;
        for(int i =0;i<n;i++){
            ctn += NumberofElementsLesserMid(matrix[i],mid);
        }
        if(ctn <= ((n*m)/2)){
            low = mid +1;
        }else{
            high = mid-1;
        }
        
    }
    
  
    return low;
}

int main(){

  vector<vector<int>> mat = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9},
    };


    cout << medianBS(mat);


return 0;
}