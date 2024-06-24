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

    // Print the data of the nodes
    Node *temp = Head;
    while(temp!= NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}