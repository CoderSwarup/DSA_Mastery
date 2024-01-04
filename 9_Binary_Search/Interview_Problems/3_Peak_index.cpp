/// https://leetcode.com/problems/peak-index-in-a-mountain-array/
#include<iostream>
using namespace std;
int peakElem(int arr[],int n){
    int s= 0;
    int l = n-1;

    int mid = s+(l-s)/2;
    while(s<l){
        
        if(arr[mid] > arr[mid+1]){
            l = mid;
        }else{
            s = mid +1;
        }

        mid = s+(l-s)/2;
    }

    return s;
}

int main(){


   int arr1[3] = {0, 1, 0};
    std::cout << "Peak Element in arr1: " << peakElem(arr1, 3) << std::endl;

    int arr2[5] = {1, 3, 20, 4, 1};
    std::cout << "Peak Element in arr2: " << peakElem(arr2, 5) << std::endl;

    int arr3[5] = {10, 20, 15, 2,1};
    std::cout << "Peak Element in arr3: " << peakElem(arr3, 5) << std::endl;

return 0;
}