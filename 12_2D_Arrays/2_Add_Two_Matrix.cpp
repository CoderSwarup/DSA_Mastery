#include<iostream>
using namespace std;

void print2dArray(int arr[][3],int n , int m){
    for (int i = 0 ;i <n ; i++){
        for (int j=0 ;j <m ; j++){
            cout << arr[i][j]<<" ";        
        }
       cout << endl;
    }
}


int main(){

      int arr[4][3] = {1,2,3,4,5,6,7,8,9,10,11,12};
      int arr2[4][3] = {12,11,10,9,8,7,6,5,4,3,2,1};
      int ans[4][3];


    // time compelaxity = O(row*col)
    //space complexity = O(row+col)

    for(int i =0; i<4;i++){
        for (int j=0;j<3;j++)
        {
            ans[i][j] = arr[i][j] + arr2[i][j];
        }
    }

     print2dArray(ans,4,3);

return 0;
}