#include<iostream>
using namespace std;
#include <bits/stdc++.h>


class Node{
    public:
    int data;
    Node *left , *right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};


// Using Recursion 
void BSTRecursion(int arr[],int &index,int lower ,int upper,int N){
    
if(index==N || lower > arr[index] || upper < arr[index]) return;


int value = arr[index++];

BST(arr,index,lower,value,N);
BST(arr,index,value,upper,N);
}


int canRepresentBSTUsingRecursion(int arr[], int N) {
    // code here
    int index = 0;
    BST(arr,index,INT_MIN,INT_MAX,N);
    

    return index==N;
}

int main(){
    int N = 3;
    int arr[] = {2, 4, 3};

    int ans = canRepresentBSTUsingRecursion(arr,N);

    cout << "The give Preorder is BST  : " << (ans == 1 ? "YES" : "NO") ;


return 0;
}