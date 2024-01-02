#include<iostream>
using namespace std;


void PintArray(int arr[] ,int n){
    cout << endl;
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }

    cout << endl;
}


// void AlternateSwap(int arr[],int n){
//     int startpos = 0;
//     int endpos = 1;
        
//     while(endpos<n){
//         swap(arr[startpos],arr[endpos]);
//         startpos +=2;
//         endpos +=2;
//     }

//     PintArray(arr,n);
// }


// approach to
void AlternateSwap(int arr[],int n){

    for(int i=0;i<=n;i+=2){
        if(arr[i+1]>=n){
            break;
        }
        swap(arr[i],arr[i+1]);
    }

    PintArray(arr,n);
}

int main(){

    int arr[5] = {1,2,3,4,5};
    AlternateSwap(arr,5);

    int arr2[6] = {1,2,3,4,5,6};
    AlternateSwap(arr2,6);

return 0;
}