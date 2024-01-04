#include<iostream>
using namespace std;

// Find The Pivot Element in rotated Array 

// Pivot Element Means the Minimum element in the array
int getPivotElement(int arr[], int n){
    int s = 0;
    int e = n -1;
    int mid = s + (e - s)/2;
    while(s<e){


        if(arr[mid] >= arr[0]){
            s = mid +1;
        }else{
            e = mid;
        }

        mid = s+ (e-s)/2;

    }

    // s and e return Same Index
    return s;
    // return e;
}

    int main(){

    int arr[] = {4,8,1,2,3};
    int size = sizeof(arr) /sizeof(int);

    cout << "Pivot Element " << getPivotElement(arr,size);


return 0;
}