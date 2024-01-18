#include<iostream>
using namespace std;
#include<vector>

int main(){


    // vector<vector<int>>matrix;
    // vector<vector<int>>matrix(3,vector<int>(3,1));


    // for(int i= 0;i<3;i++){
    //     for(int j=0;j<3;j++){
    //         cout<<matrix[i][j] << " ";
    //     }
    // }


    // take input
    int m , n;
    cin>> m >> n;

    vector<vector<int>>matrix1(m,vector<int>(n));


    for(int i= 0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>matrix1[i][j];
        }
    }


    
    for(int i= 0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<matrix1[i][j] << " ";
        }
    }


    int row = matrix1.size();
    int col = matrix1[0].size();

    cout << endl << row << col ;

return 0;
}