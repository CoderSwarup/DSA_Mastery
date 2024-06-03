#include<iostream>
using namespace std;
#include <bits/stdc++.h>

void SortArrM1(vector<int> &arr,int start,int mid,int end){
    int left = start;     // starting index of left half of arr
    int right = mid + 1; // starting index of right half of arr

    // Merge the two halves in-place
    while (left <= mid && right <= end) {
        if (arr[left] <= arr[right]) {
            left++;
        } else {
            // Element at right is smaller than element at left
            // We need to shift the element at right to the correct position
            int value = arr[right];
            int index = right;

            // Shift all elements between left and right one position to the right
            while (index > left) {
                arr[index] = arr[index - 1];
                index--;
            }
            arr[left] = value;

            // Update all pointers
            left++;
            mid++;
            right++;
        }
    }

}
void SortArrM2(vector<int> &arr,int start,int mid,int end){
    int left = start;     
    int right = mid + 1; 
    vector<int> temp;


    while(left <= mid && right <= end){

        // use >= for the Decreasing 
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            right++;
        }
    }


    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }

    while(right<=end){
        temp.push_back(arr[right++]);
    }

    //
    // int i =0;
    // while(start<=end){
    //     arr[start++] = temp[i++];
    // }

    for(int i=start;i<=end;i++){
        arr[i] = temp[i-start];

    }

 

}



void mergeSort( vector<int> &arr,int start,int end){
    if(start >= end)return; // base case when start and end == 1
    int mid = start + ((end-start)/2);
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);
    SortArrM2(arr,start,mid,end);
}   



int main(){
    vector<int> arr = {9, 4, 7, 6, 3, 1, 5}  ;
    int n = 7;

    cout << "Before Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }
    cout << endl;
    mergeSort(arr, 0, n - 1);
    cout << "After Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }
    cout << endl;
    return 0 ;
}