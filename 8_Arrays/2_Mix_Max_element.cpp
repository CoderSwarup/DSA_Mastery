#include<iostream>
#include <limits.h>

using namespace std;

int getMax(int arr[],int n){
    int maxi = INT_MIN;

    for(int i = 0;i<n;i++){

        // Default Function by cpp
        maxi = max(maxi,arr[i]);
        // if(max < arr[i]){
        //     max = arr[i];
        // }
    }

    return maxi;
}

int getMin(int arr[],int n){
    int min = INT_MAX;

    for(int i = 0; i<n; i++){
        //mini=   min(min,arr[i])
        // if(min > arr[i]){
        //     min = arr[i];
        // }
    }

    return min;
}

int main(){

    int num;
    cin >> num;

    // int arr[num] ;  // ==> bad Practice 
    int arr[100];

    for(int i=0;i <num;i++){
        cin >> arr[i];
        cout << endl;
    }

    cout << "Max Element  is " << getMax(arr,num) << endl;
    cout << "Min Element  is " << getMin(arr,num) << endl;
    


return 0;
}