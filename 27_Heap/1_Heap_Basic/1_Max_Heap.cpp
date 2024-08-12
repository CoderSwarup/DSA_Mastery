#include<iostream>
using namespace std;
#include <bits/stdc++.h>

class MaxHeap{

    int *arr;
    int size; // total element in heap
    int total_size; // Total Size of the array

    public:

    MaxHeap(int n){
        arr =new int[n];
        total_size =n;
        size=0;
    }

    // insert in the Heao
    void insertHeap(int val){

        // is heap full
        if(size == total_size){
            cout <<"Heap is Full" <<endl;
            return;
        }

        arr[size] =val;
        int index = size;
        size++;

        // Maintain the Maxheap property

        while(index > 0 && arr[(index-1) /2]<arr[index]){
            swap(arr[(index-1) /2],arr[index]);
            index = (index-1) /2;
        }


        cout << arr[index] << " Is Inserted into the heap" << endl;
    }

    void print(){
        cout  << "Print the Element of the Heap : " ;
        for(int i=0;i<size;i++){
            cout << arr[i] << " ";
        }

        cout  << endl;
    }


    // Deletion 

    void Delete(){
        if(size == 0){
            cout << "Heap is the UnderFlow " << endl;
            return;
        }


        cout << arr[0] << " Element is deleted "<<endl;
        arr[0] = arr[size-1];

        size--;

        if(size==0){
            return;
        }


        Heapify(0);
    }

    void  Heapify(int index){
       
        

        int largest = index;
        int left = (2*index)+1;  // left = (index * 2 )+1
        int right = (2*index)+2; // left = (index * 2 )+2

        // largest will store the index of the element which 
        // is greaer between parent ,left child and right child

        if(left<size && arr[left]>arr[largest]){
            largest =left;
        }
         if(right <size && arr[right] > arr[largest]){
            largest = right;
        }

        if(largest != index){
            swap(arr[index],arr[largest]);
            Heapify(largest);
        }


        return;
        
    }

};

int main(){

    MaxHeap H(6);
    H.insertHeap(2);
    H.insertHeap(3);
    // H.insertHeap(4);
    // H.insertHeap(1);

    H.print();

    H.insertHeap(11);
    H.insertHeap(21);
    H.insertHeap(12);
    H.insertHeap(10);

      H.print();

    H.Delete();
    H.Delete();
    H.Delete();
    H.Delete();
    H.Delete();
    H.Delete();
    H.Delete();
    H.print();





return 0;
}