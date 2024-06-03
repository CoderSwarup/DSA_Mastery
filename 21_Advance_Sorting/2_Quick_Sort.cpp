#include<iostream>
using namespace std;
#include <bits/stdc++.h>

int partiction(vector<int> &arr, int start ,int end){

    int pos = start;

    while(start<=end){  
        if(arr[start]<=arr[end]){
            swap(arr[start],arr[pos]);
            pos++;
       }
       start++;
    }

    return pos-1;
}
void QS(vector<int> &arr, int start ,int end){
    if(start>=end) return;

    int pivot = partiction(arr,start , end);
    //left

    QS(arr,start,pivot-1);
    QS(arr,pivot+1,end);
}


int main(){


  vector<int> arr = {9, 4, 7, 6, 3, 1, 5}  ;
    int n = 7;

    cout << "Before Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }
    cout << endl;
    QS(arr, 0, n - 1);
    cout << "After Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }
    cout << endl;
    return 0 ;
}