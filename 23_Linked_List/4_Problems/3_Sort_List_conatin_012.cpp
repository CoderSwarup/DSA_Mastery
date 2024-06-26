
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



Node* segregate(Node *head) {
     
     // Add code here
     Node *curr= head;
     int c0 =0,c1=0,c2=0;
     
     while(curr){
         if(curr->data==0){
             c0++;
         }
         else if(curr->data==1){
             c1++;
         }
         else{
             c2++;
         }
         curr= curr->next;
     }
     
     curr = head;
     // insert the values
     while(c0--){
         curr->data = 0;
         curr = curr->next;
     }
     while(c1--){
         curr->data = 1;
         curr = curr->next;
     }
     while(c2--){
         curr->data = 2;
         curr = curr->next;
     }
     
     return head;
 }

int main(){

    Node *Head = new Node(1);
    Node *temp1 = new Node(0);
    Head->next  = temp1;
    Node *temp2 = new Node(1);
    temp1->next  = temp2;
    Node *temp3 = new Node(2);
    temp2->next  = temp3;
    Node *temp4 = new Node(0);
    temp3->next  = temp4;

    Node *t = Head;

    while(t){
        cout<<t->data<<" ";
        t = t->next;
    }

    Head = segregate(Head);
    
    cout << endl;
    t = Head;

    while(t){
        cout<<t->data<<" ";
        t = t->next;
    }

 



return 0;
}