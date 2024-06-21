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


Node* ReverseLL(Node *prev,Node *curr){
    if(curr==NULL){
        return prev;
    }

    Node *t = curr->next;
    curr->next = prev;
    // prev = curr;
    // curr = t;

    // return ReverseLL(prev,curr);

    //*** OR ********** */
    return ReverseLL(curr,t);
}

int main(){
    Node *Head = new Node(20);
    Head->next = new Node(30);
    Head->next->next = new Node(40);
    Node *N = new Node(50);
    Head->next->next->next  = N;
    Node *NN = new Node(60);
     N->next  = NN;


    Node *t = Head;
    while(t!=NULL){
        cout << t->data << " ";
        t = t->next;

    }
    Node *prev = NULL;
    Node *curr = Head;
    
    Head = ReverseLL(prev,curr);
    
    cout << endl ;

    t = Head;
    while(t!=NULL){
        cout << t->data << " ";
        t = t->next;

    }




return 0;
}