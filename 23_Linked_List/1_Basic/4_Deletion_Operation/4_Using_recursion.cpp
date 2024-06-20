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

Node * DeleteUsignRursion(Node *curr,int x){
    if(x==1){
        Node *temp = curr->next;
        delete curr;
        return temp;
    }

    curr->next = DeleteUsignRursion(curr->next,x-1);
    return curr;
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


    // if ll has Only one Node
   if(Head==NULL){
    cout << "Linked List is empty" << endl;
    return 0;
   }else{
    int x = 3;
    Head= DeleteUsignRursion(Head,x);
   }

    cout << "\nAfter Deleting the At Postion 3rd position  Node data is 40" << endl;

    t= Head;
    while(t!=NULL){
        cout << t->data << " ";
        t = t->next;

    }
return 0;
}