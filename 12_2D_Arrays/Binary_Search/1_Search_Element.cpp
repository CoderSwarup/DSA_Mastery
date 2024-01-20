#include<iostream>
using namespace std;
#include<vector>

// ==> https://leetcode.com/problems/search-a-2d-matrix/description/


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

int BinarySearch2DMatrix(vector<vector<int>> &matrix,int Target){

    int row = matrix.size();
    int col = matrix[0].size();


    for(int i=0;i < row;i++){
        if(matrix[i][0] <= Target && Target <= matrix[i][col-1] ){
           int s= 0;
           int e = col-1;
           while(s<=e){
           int mid = s + (e-s)/2;
            if(matrix[i][mid] == Target){
                return 1;
            }

            if(matrix[i][mid] <= Target){
                s = mid+1;
            }else{
                e=mid-1;
            }

           }


           return 0;
        }
    }

    return 0;

}


// Using Row Major Formula 
// Assuming the 2d Array is Single Array 
// starti = 0 , endi = row * col
// mid = start + (endi-starti)/2;
// rowindex = mid/NoofCol
// colindex = mid%noOfCol
/* if (matrix[rowindex][colindex] == Target) {
    return 
}*/
// ....

int BinarySearch2DMatrixOptimalApproach(vector<vector<int>> &matrix,int Target){
        int row = matrix.size();
        int col = matrix[0].size();
        int s = 0;
        int e = row*col-1;
            
            int rowindex;
            int colindex ;

        while(s<=e){
            int mid = s + (e-s)/2;
             rowindex = mid/col;
            colindex = mid%col;
           

            if(matrix[rowindex][colindex] == Target){
                return 1;
            }else if(matrix[rowindex][colindex] <= Target){
                s = mid+1;
            }else{
                e=mid-1;
            }
        }


        return 0;



}
int main(){


    vector<vector<int>> matrix = {{1,2,3}};

    // cout << BinarySearch2DMatrix(matrix,57);
    cout << BinarySearch2DMatrixOptimalApproach(matrix,11);


return 0;
}