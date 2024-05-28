#include<iostream>
using namespace std;
#include <bits/stdc++.h>


//Binary Search 
// tc O(N) * O(LogM)

bool isElement(vector<int> arr , int n ,int target){
    int start = 0;
    int end = n-1;

    while(start<=end){
        int mid = start +((end-start)/2);
        if(arr[mid] == target){
            return true;
        }else if(target > arr[mid]){
            start = mid +1;
        }else{
            end = mid -1;
        }
    }

    return false;
}

 bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    
    for(int i=0;i<n;i++){
        if(matrix[i][0] <= target && matrix[i][m-1] >= target){
            return isElement(matrix[i],m,target);
        }
    }
    return false;
 }


bool searchMatrixBinarySearch(vector<vector<int>>& matrix, int target){
    int n = matrix.size();
    int m = matrix[0].size();

    int low =0;
    int high = n*m-1;

    while(low <= high){
        int mid = low + ((high-low)/2);
        int row = mid/m;  // row is the multiply of the col 
        int col = mid%m; // total element are present col in the column = 0 => col-1

        if(matrix[row][col] == target){
            return true;
        }else if(matrix[row][col] > target){
            high = mid-1;
        }else{
            low = mid+1;
        }

    }

    return false;

}
int main(){
    vector<vector<int>> arr =
           {{1,3,5,7},
           {0, 0, 1, 1},
           {23,30,34,60}};

    // cout << searchMatrix(arr, 213);
    cout << searchMatrixBinarySearch(arr, 23);


return 0;
}