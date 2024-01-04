#include<iostream>
using namespace std;
#include <vector>
// https://www.codingninjas.com/studio/problems/search-in-rotated-sorted-array_1082554
// Sample Input 1:
// 4 3
// 8 9 4 5


// Sample output 1:
// -1 


// Explanation of Sample Output 1:
// For the test case, 3 is not present in the array. Hence the output will be -1.


// Sample Input 2:
// 4 3
// 2 3 5 8


// Sample output 2:
// 1


int getPivotPoint(vector<int>& arr , int n){
    int s = 0;
    int e = n-1;
    int mid = s +(e-s)/2;
    while (s < e) {
        if(arr[mid] >= arr[0]){
            s = mid +1;
        }else{
            e = mid;
        }
        mid = s +(e-s)/2;
    }
    return s;
}


int BinarySearch(vector<int>& arr,int start,int n,int k){
    int s = start;
    int e = n-1;
    int ans = -1;


    while(s<=e){
        int mid = s +(e-s)/2;
        if(arr[mid] == k){
            ans = mid;
        }


        if(arr[mid] > k){
            e = mid -1;
        }else{
            s= mid+1;
        }
    }

    return ans;
}


int main(){


    vector<int>arr = {51, 81,12 ,23 };
    int k = 811;
    int pivot = getPivotPoint(arr,arr.size());



    if(k >=arr[pivot] && k <= arr[arr.size()-1]    ){
        cout << "Element is present at index: "<<BinarySearch(arr,pivot,arr.size(),k);
    }else{
        cout << "Element is present at index: "<<BinarySearch(arr,0,pivot,k);
    }


    return 0;
}