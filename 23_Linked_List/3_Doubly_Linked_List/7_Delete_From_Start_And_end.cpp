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

Node* DeleteFromStart(Node *Head){
    if(Head == NULL){
        cout<<"List is empty"<<endl;
        return NULL;
    }else{
        Node *temp = Head;
        Head->next->prev = NULL;
        Head = temp->next;
        delete temp;
        return Head;

    }
}


Node* DeleteFromEnd(Node *Head){
    if(Head == NULL){
        cout<<"List is empty"<<endl;
        return NULL;
    }else if(Head->next == NULL){
        delete Head;
        return NULL;
    }else{
        Node *temp = Head;
        Node *prev =NULL;
        while(temp->next != NULL){
            prev = temp;
            temp = temp->next;
        }
        // prev->next = NULL;
        temp->prev->next = NULL;
        delete temp;
        return Head;
    }
}

int main(){
    // Create a new doubly linked list
    Node *Head = new Node(20);
    Node *second = new Node(30);
    Node *third = new Node(40);

    // Link the nodes
    Head->next = second;
    second->prev = Head;
    second->next = third;
    third->prev = second;

    // Head = DeleteFromStart(Head);
    Head = DeleteFromEnd(Head);


    // Print the data of the nodes
    Node *temp = Head;
    while(temp!= NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}