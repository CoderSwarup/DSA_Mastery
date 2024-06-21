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


int MiddleOfLL(int count ,Node *Head){
    int m = (count/2) ;
    Node *temp = Head;
    while(m--){
        temp=temp->next;
     }

  return temp->data;
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
    
    int count =0;
    t = Head;
    while(t!=NULL){
        count++;
        t =t->next;
    }
    // cout << count << endl;

    int data = MiddleOfLL(count,Head);

    cout << endl << "Middle is : " << data;
    

    





return 0;
}