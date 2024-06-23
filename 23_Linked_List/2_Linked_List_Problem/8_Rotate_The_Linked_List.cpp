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


Node* rotateRight(Node* head, int k) {
        
        if(head==NULL || head->next ==NULL){
            return head;
        }

        int count =0;
        Node *temp = head;
        while(temp){
            count++;
            temp = temp->next;
        }

        k = k%count;
        if(k==0) return head;
        count -= k;

        Node *prev = NULL;
        Node *curr = head;
        while(count--){
            prev = curr;
            curr = curr->next;
        }

        Node* tail = curr;

        while(tail->next!=NULL){
            tail = tail->next;
        }

        prev->next = NULL;
        tail->next = head;
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
    Node *NNN = new Node(670);
     NN->next  = NNN;
     

    Head = rotateRight(Head,2);
    Node *t = Head;
    while(t!=NULL){
        cout << t->data << " ";
        t = t->next;

    }
    
   

return 0;
}