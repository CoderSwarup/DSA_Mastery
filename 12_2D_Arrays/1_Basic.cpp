#include<iostream>
using namespace std;


// How TO pass the function 
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

    for(int i =0; i<4;i++){
        for (int j=0;j<3;j++)
        {
            cout << arr[i][j] << " ";
        }
    }
    cout << endl;
    print2dArray(arr,4,3);

return 0;
}