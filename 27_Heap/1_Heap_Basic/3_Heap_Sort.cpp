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



void printHeap(int arr[],int n){
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";

    }

    cout << endl;
}


void HeapSort(int arr[],int n){
    for(int i=n-1;i>0;i--){
        swap(arr[i],arr[0]);
        HeapifyStepDown(arr,0,i);
    }
}

// TC O(Nlog(N))
// SC O(N) || O(1) itterative approach

int main(){
    int arr[] = {10,3,8,9,5,13,18,14,11,70};
    cout << "Heap Sort " << endl;
    buildMaxHeap(arr,10);
    HeapSort(arr,10);

    printHeap(arr,10);



return 0;
}