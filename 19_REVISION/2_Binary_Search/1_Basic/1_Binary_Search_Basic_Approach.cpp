
#include<iostream>
using namespace std;
#include <bits/stdc++.h>

int BinarySearch(vector<int> arr , int low , int high , int target){

    if(low > high) return -1;
    int mid = low +((high -low)/2);
    if(arr[mid] == target) return mid;
    else if(arr[mid] > target) 
    return BinarySearch(arr, low, mid -1,target);
     return BinarySearch(arr, mid +1, high,target);
   
}

int main(){


    vector<int>arr = {-1,0,3,5,9,12};
    cout << BinarySearch(arr, 0, arr.size()-1,9);


return 0;
}