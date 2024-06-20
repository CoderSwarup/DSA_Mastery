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

    Head = NULL;


   if(Head==NULL){
    cout << "Linked List is empty" << endl;
    return 0;
   }else{
     Node *temp = Head;
    Head = Head->next;
    delete temp;
   }

    cout << "\nIDeleting the First Node" << endl;

    t= Head;
    while(t!=NULL){
        cout << t->data << " ";
        t = t->next;

    }
return 0;
}