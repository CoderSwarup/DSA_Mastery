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
    Node *NNN = new Node(670);
     NN->next  = NNN;


    Node *t = Head;
    while(t!=NULL){
        cout << t->data << " ";
        t = t->next;

    }
    
   
   Node *slow = Head;
   Node *fast = Head;

    while(fast != NULL &&fast->next != NULL ){
        fast = fast->next;
        fast = fast->next;
        slow = slow->next;

    }
    

    cout << endl << "Middle " << slow << " Data " << slow->data <<endl; 





return 0;
}