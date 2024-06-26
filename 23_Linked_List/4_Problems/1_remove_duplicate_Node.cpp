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

Node *removeDuplicatesUsingSet(Node *head)
{
 // your code goes here
 set<int>ans;
 Node *curr = head;
 
 while(curr){
     ans.insert(curr->data);
     curr = curr->next;
 }
 
 head = NULL;
 curr = head;
  set<int, greater<int> >::iterator i;
   for ( i = ans.begin(); i != ans.end(); i++) {
     if(curr== NULL){
         head = new Node(*i);
         curr =head;
     }else{
         Node *t = new Node(*i);
         curr->next = t;
         curr = t;
     }
 }
 return head;
}

Node *removeDuplicates(Node *head)
{
    // your code goes here Without Using Extra Space
    if(!head || !head->next)
    return head;
    Node *curr = head->next;
    Node *prev = head;
    
    while(curr){
        if(prev->data == curr->data){
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }else{
            prev = prev->next;
            curr = curr->next;
        }
    }
    
    return head;
 
 
}
int main(){

    Node *Head = new Node(1);
    Node *temp1 = new Node(1);
    Head->next  = temp1;
    Node *temp2 = new Node(2);
    temp1->next  = temp2;
    Node *temp3 = new Node(2);
    temp2->next  = temp3;
    Node *temp4 = new Node(4);
    temp3->next  = temp4;

    Node *t = Head;

    while(t){
        cout<<t->data<<" ";
        t = t->next;
    }

    // Head = removeDuplicatesUsingSet(Head);
    Head = removeDuplicates(Head);
    
    cout << endl;
    t = Head;

    while(t){
        cout<<t->data<<" ";
        t = t->next;
    }

 



return 0;
}