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

void ReverseRowOfArray(int arr[][3],int n , int m){
    for (int i = 0 ;i <n ; i++){
      int s = i;
      int e = m -1;
        while(s<e){
          
            swap(arr[i][s],arr[i][e]);
            s++;
            e--;
        }
            
          
    }
}

int main(){

    int arr[4][3] = {1,2,3,4,5,6,7,8,9,10,11,12};
     print2dArray(arr,4,3);

    ReverseRowOfArray(arr,4,3);
    cout << "After Re4verse \n"<<endl;
    print2dArray(arr,4,3);

return 0;
}