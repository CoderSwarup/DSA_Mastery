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

int main(){

    // Node *Head = NULL;
    Node *Head = new Node(20);

    
    Node *tail = Head;

    while(tail->next !=NULL){
        tail = tail->next;
    }


    // heck The LL is Not Null
    if(tail== NULL){
        Head = new Node(222);
    }else{
        Node *temp = new Node(2);
        temp->prev = tail;
        tail->next = temp;
    }

   
    // Print the data of the nodes
    Node *temp = Head;
    while(temp!= NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}