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
    // Create a new doubly linked list
    Node *Head = new Node(20);
    Node *second = new Node(30);
    Node *third = new Node(40);

    // Link the nodes
    Head->next = second;
    second->prev = Head;
    second->next = third;
    third->prev = second;

    //DELETE FORM THE POS
    int pos = 13;

    if(Head == NULL){
        cout<<"List is empty"<<endl;
    }else if(Head->next == NULL){
        delete Head;
        Head = NULL;
    }else{

        Node *curr = Head;

        while(--pos && curr->next != NULL){
            curr = curr->next;
        }

        if(curr->next == NULL){
            curr->prev->next = NULL;
            delete curr;
        }else{
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            delete curr;
        }
    }


    // Print the data of the nodes
    Node *temp = Head;
    while(temp!= NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}