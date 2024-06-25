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
    
    // Head = NULL;
    //insert At Postion 2
    int pos = 0;
    
    if(Head == NULL){
        Head = new Node(20);
    }
    else if(pos==0){
        // check is node Not Empty 
     
            Node *temp = new Node(10);
            temp->next = Head;
            Head->prev = temp;
            Head= temp;
        
    }else{
        Node *curr = Head;
        while(--pos ){
            curr = curr->next;
        }
           
        if(curr->next == NULL){

             Node *temp = new Node(10);
             temp->prev = curr;
             curr->next = temp;
        }else{
            Node *temp = new Node(10);
            temp->prev = curr;
            temp->next = curr->next;
            curr->next->prev = temp;
            curr->next = temp;
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