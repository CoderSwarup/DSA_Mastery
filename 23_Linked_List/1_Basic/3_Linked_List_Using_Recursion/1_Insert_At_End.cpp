#include<iostream>
using namespace std;
#include <bits/stdc++.h>

class Node{
    public:

    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

// TC O(N)

Node* InsertAtEnd(int arr[],int i,int size){

    if(i==size){
        return NULL;
    }

    Node* temp = new Node(arr[i++]);
    temp->next = InsertAtEnd(arr,i,size);
    return temp;
}

int main(){

    Node *Head;
    Head = NULL;

    // Node *a = new Node(12);
    // cout << a->data<<endl;


      int arr[4] = {1,2,3,4};

        Head = InsertAtEnd(arr,0,4);

    Node *temp = Head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }

return 0;
}