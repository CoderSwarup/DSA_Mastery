#include<iostream>
using namespace std;


int SecondHighest(int arr[] , int n){
    // Initialize the two highest elements
    int high1 = -1, high2 = -1;
    for (int i=0; i < n ;i++ ) {
        if (high1 == -1 || arr[i] > high1) {
            high2 = high1;
            high1 = arr[i];
        } else if (high2 == -1 || arr[i] > high2 && arr[i] != high1)
        high2 = arr[i];
    }
        return high2;
}


int main(){

int arr[6] ={2,3,6,4,8,5};
cout << SecondHighest(arr,6);

return 0;
}