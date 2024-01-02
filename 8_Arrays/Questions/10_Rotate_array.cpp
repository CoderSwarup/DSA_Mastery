#include<iostream>
using namespace std;


void PintArray(int arr[] ,int n){
    cout << endl;
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }

    cout << endl;
}


int rotateArray(int arr[],int n){
    int temp = arr[n-1];

    for(int i =n-2; i>=0; i--){
        arr[i+1]=arr[i];
    }

    arr[0] = temp;

}

int main(){

    int arr[5] = {1,2,3,4,5};
    rotateArray(arr,5);
    PintArray(arr,5);


return 0;
}