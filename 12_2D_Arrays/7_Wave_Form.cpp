






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

void WareForm( int arr[][3],int row , int col){


    // cout << row << col;
    for(int i=0;i<col;i++){

      if(i%2==0){
          for(int j=0;j<row;j++){
            cout<<arr[j][i] << " ";
        }
      }else{
          for(int j=row-1;j>=0;j--){
            cout<<arr[j][i] << " ";
        }
    }
    }


}


// Time Complexity = O(row*col)
// space Complexity = O(1)

int main(){

    int arr[4][3] = {1,2,3,4,5,6,7,8,9,10,11,12};
     print2dArray(arr,4,3);

    cout << endl;
    WareForm(arr,4,3);


return 0;
}