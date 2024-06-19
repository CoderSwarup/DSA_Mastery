#include<iostream>
using namespace std;
#include <bits/stdc++.h>


class Node{
    public:
    int data;
    Node* next;

    Node(int value ){
        data = value;
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

    cout << "\nInsert the New Value 35 after 30 and Before 40" << endl;

    Node *temp = Head;
    int x = 2;
    x--;

    while(x--){
        temp = temp->next;
    }

    Node *t2 = new Node(35);
    t2->next = temp->next;
    temp->next= t2;

    cout << "After Inserting Value"<< endl;

    Node *tt = Head;
    while(tt!=NULL){
        cout << tt->data << " ";
        tt = tt->next;

    }


return 0;
}