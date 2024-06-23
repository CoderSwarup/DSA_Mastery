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
Node* removeEverykthNode(Node* head, int k) {
        if(k==1) return NULL;

        int count =1;
        Node* prev = NULL;
        Node *curr = head;

        while(curr){
            if(count%k == 0){
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }else{
                prev = curr;
                curr = curr->next;
            }
            count++;
        }

        return head;
        

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

    Head = removeEverykthNode(Head,2);
    Node *t = Head;
    while(t!=NULL){
        cout << t->data << " ";
        t = t->next;

    }
    
   

return 0;
}