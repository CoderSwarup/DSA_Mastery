// build the Heap using the step down ,and O(N ) Time complexity
#include<iostream>
using namespace std;
#include <bits/stdc++.h>


// Build Max heap
// TC O(N)
void  HeapifyStepDown(int arr[],int index ,int n){
    int largest = index;
    int left = 2*index+1;
    int right = 2*index+2;

    if(left<n && arr[left] >arr[largest]){
        largest =left;
    }
    
    if(right<n && arr[right] >arr[largest]){
        largest =right;
    }

    if(largest != index){
        swap(arr[largest],arr[index]);
        HeapifyStepDown(arr,largest,n);
    }
}

void buildMaxHeap(int arr[],int n){

    int start = (n/2)-1;

    for(int i=start;i>=0;i--){
        HeapifyStepDown(arr,i,n);
    }
}


// Build Max heap
// TC O(N)
void  HeapifyStepDownMinHep(int arr[],int index ,int n){
    int largest = index;
    int left = 2*index+1;
    int right = 2*index+2;

    if(left<n && arr[left] <arr[largest]){
        largest =left;
    }
    
    if(right<n && arr[right] <arr[largest]){
        largest =right;
    }

    if(largest != index){
        swap(arr[largest],arr[index]);
        HeapifyStepDownMinHep(arr,largest,n);
    }
}
void buildMinHeap(int arr[],int n){

    int start = (n/2)-1;

    for(int i=start;i>=0;i--){
        HeapifyStepDownMinHep(arr,i,n);
    }
}

void printHeap(int arr[],int n){
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";

    }

    cout << endl;
}

int main(){
    int arr[] = {10,3,8,9,5,13,18,14,11,70};
    cout << "Build The Max Heap " << endl;
    buildMaxHeap(arr,10);
    printHeap(arr,10);

    cout << "Build The Min Heap " << endl;
    buildMinHeap(arr,10);
    printHeap(arr,10);

return 0;
}