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


Node* sortedMergeUsingExtraSpace(Node* head1, Node* head2)  
{  
    // code here
    vector<int> list;
    
    
    while(head1 && head2){
        if(head1->data<head2->data){
            list.push_back(head1->data);
            head1 = head1->next;
        }else{
            list.push_back(head2->data);
            head2 = head2->next;
        }
    }
    
    while(head1){
        list.push_back(head1->data);
        head1 = head1->next;
    }
    
    while(head2){
         list.push_back(head2->data);
          head2 = head2->next;
    }
    
    Node *Head = NULL;
    Node*tail = Head;
    for(int i=0;i<list.size();i++){
        if(Head==NULL){
            Head = new Node(list[i]);
            tail = Head;
        }else{
            Node *t = new Node(list[i]);
            tail->next = t;
            tail = t;
        }
    }
    
    return Head;
    
    
}  


Node* sortedMerge(Node* head1, Node* head2)  
{  
    // code here
    Node *Head = new Node(0);
    Node *tail = Head;
    
     while(head1 && head2){
        if(head1->data<head2->data){
            tail->next = head1;
            head1 = head1->next;
            tail = tail->next;
            tail->next = NULL;
        }else{
            tail->next = head2;
            head2 = head2->next;
            tail = tail->next;
            tail->next = NULL;
        }
    }
    
    
    if(head1){
        tail->next=head1;
    }
    if(head2){
        tail->next=head2;
    }
    
    tail = Head;
    Head = Head->next;
    delete tail;
    
    return Head;
    
    
}  

int main(){

    Node *Head = new Node(5);
    Node *temp1 = new Node(10);
    Head->next  = temp1;
    Node *temp2 = new Node(15);
    temp1->next  = temp2;
    Node *temp3 = new Node(40);
    temp2->next  = temp3;
    Node *temp4 = new Node(45);
    temp3->next  = temp4;


    Node *Head2 = new Node(2);
    Node *temp11 = new Node(20);
    Head2->next  = temp11;
    Node *temp22 = new Node(32);
    temp11->next  = temp22;
    Node *temp33 = new Node(52);
    temp22->next  = temp33;

    Node *t = Head;
    cout << "List 1 :" << endl;
    while(t){
        cout<<t->data<<" ";
        t = t->next;
    }

    t = Head2;
    cout << endl << "List 2 :" << endl;
    while(t){
        cout<<t->data<<" ";
        t = t->next;
    }

    // Head = sortedMergeUsingExtraSpace(Head,Head2);
    Head = sortedMerge(Head,Head2);
    
    
    cout << endl << endl <<"After List Sort " << endl;

 
    t = Head;

    while(t){
        cout<<t->data<<" ";
        t = t->next;
    }



return 0;
}