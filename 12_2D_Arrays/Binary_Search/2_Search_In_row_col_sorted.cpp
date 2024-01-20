#include<iostream>
using namespace std;
#include<vector>



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

int BinarySearch(vector<vector<int>> &matrix,int target){
    int row = matrix.size();
    int col = matrix[0].size();

    int s = 0;
    int e = col-1;

    while(s<row && e>=0){
        int element = matrix[s][e];
        if (element == target){
            return 1;
        }else if(element < target){
            s++;
        }else{
            e--;
        }
    }

    return 0;
}


int main(){


    vector<vector<int>> matrix = {{4,8,15,25,60},{18,22,26,42,80},{36,40,45,68,104},{48,50,72,83,130},{70,99,114,128,170}};

    // cout << BinarySearch2DMatrix(matrix,57);
    cout << BinarySearch(matrix,40);


return 0;
}