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


Node* InsertAtBegin(int arr[],int i,int n,Node* prev){
    if(i==n){
        return prev;
    }

    Node * temp = new Node(arr[i++]);
    temp->next = prev;

    return InsertAtBegin(arr,i,n,temp);
}


Node* InsertAtBeginM2(int arr[],int i){
    if(i==0){
        return NULL;
    }

    Node * temp = new Node(arr[i-1]);
    temp->next = InsertAtBeginM2(arr,i-1);

    return temp;
}


int main(){

    Node *Head = NULL;

    int arr[5] = {1,2,3,4,5};

    // Head = InsertAtBegin(arr,0,4,Head);
    Head = InsertAtBeginM2(arr,5);


    Node*temp = Head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }


return 0;
}