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

    
    // cout << endl << "Address of NN " << NN << endl;
    // cout << endl << "Address of NN " << N->next << endl;
    // cout << "is same" << (NN==N->next) << endl;


    Node *t = Head;
    while(t!=NULL){
        cout << t->data << " ";
        t = t->next;

    }

    //Edge case 1 if Head Is Empty
   if(Head==NULL){
    cout << "Linked List is empty" << endl;
    return 0;
   }else{
    //Edge Case 2 If Hjead->next = NULL
    if(Head->next ==NULL){
        cout << endl << "Only Single Node IS present "<< endl;
        Node *temp = Head;
        Head = NULL;
        delete temp;
    }else{
        //edge case 3 if node is greater than 1
        Node * prev = NULL;
        Node *temp = Head;

        while(temp->next != NULL){
            prev = temp;
            temp = temp->next;
        }


        delete temp;
        prev->next = NULL;

        
    }
    
   }

    cout << "\nAfter Deleting the End Node" << endl;

    t= Head;
    while(t!=NULL){
        cout << t->data << " ";
        t = t->next;

    }
return 0;
}