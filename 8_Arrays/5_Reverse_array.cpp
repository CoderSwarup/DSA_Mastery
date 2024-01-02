#include<iostream>
using namespace std;


void ReverseArray(int arr[]  , int n){
    int startPos = 0;
    int endpos = n-1;

    for(int i =0; i <n;i++){
        if(startPos>endpos){
            break;
        }

        int temp = arr[startPos];
        arr[startPos] =  arr[endpos];
        arr[endpos] = temp;

        startPos++;
        endpos--;
    }
    for(int i =0; i <n;i++){
        cout << arr[i] <<" ";
        
    }

    cout << endl;
}

// using Swap () 
void ReverseArraySwap(int arr[]  , int n){
    int startPos = 0;
    int endpos = n-1;

    while(startPos<=endpos){
        swap(arr[startPos],arr[endpos]);

        startPos++;
        endpos--;
    }


    for(int i =0; i <n;i++){
        cout << arr[i] <<" ";
        
    }

    cout << endl;
}

// using the ExtraArray
void Reverse(int arr[],int n){
    int arr2[n];

    // for(int i=n-1;i>=0;i--){
    //     arr2[(n-1)-i] = arr[i];
    // }


    for(int i=0;i<=n;i++){
        int temp = arr[i];
        arr[i] = arr[n-i];
        arr[n-i] = temp;
    }

        for(int i =0; i <n;i++){
        cout << arr[i] <<" ";
        // cout << arr2[i] <<" ";
        
    }

    cout << endl;
}


int main(){

    int arr[5] = {1,2,3,4,5};
    int arr2[4] = {2,-3,1,4};

    ReverseArray(arr,5);
    ReverseArray(arr2,4);

    cout << endl;

    ReverseArraySwap(arr,5);
    ReverseArraySwap(arr2,4);

    cout << endl;

    Reverse(arr,5);
    Reverse(arr2,4);


    int arr3[1] = {0};
    Reverse(arr3,1);
return 0;
}