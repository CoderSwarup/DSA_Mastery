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
Node* removeNthFromEnd(Node* head, int n) {
        Node *temp = head;
        int count = 0;
        while(temp!= NULL){
            count++;
            temp = temp->next;
        }
        count -= n;

        if(count == 0){
            temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        Node *prev =NULL;
        Node *curr =head;
        while(count--){
            prev  = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        delete curr;
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

    Head = removeNthFromEnd(Head,4);
    Node *t = Head;
    while(t!=NULL){
        cout << t->data << " ";
        t = t->next;

    }
    
   

return 0;
}