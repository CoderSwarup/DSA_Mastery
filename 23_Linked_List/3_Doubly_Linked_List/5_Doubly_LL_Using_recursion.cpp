#include<iostream>
using namespace std;
#include <bits/stdc++.h>


class Node {
    public:
    int data;
    Node *prev , *next;

    Node(int val){
        data = val;
        prev = NULL;
        next = NULL;
    }
};

Node* CreateLLUsingRecursion(vector<int>&arr,int i,int n,Node *prev){
    if(i==n){
        return NULL;
    }

    Node *temp = new Node(arr[i++]);
    temp->prev = prev;
    prev = temp;
    temp->next =CreateLLUsingRecursion(arr,i,n,prev);

    return temp;
    
}

int main(){

    Node *Head = NULL;
    vector<int>arr = {1,2,3,4,5};

    Head = CreateLLUsingRecursion(arr,0,arr.size(),Head);
   
    
   
    // Print the data of the nodes
    Node *temp = Head;
    while(temp!= NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}