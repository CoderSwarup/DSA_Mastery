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

 

int findTheLengthOfLoop(Node* head)
{
    // your code here

    Node *fast = head;
    Node *slow = head;

    int count =1;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(slow == fast){
            slow = fast->next;
            while(slow != fast){
                count++;
                slow = slow->next;
            }
            return count;
        }
        
    }
    
    return 0;
}
int main(){
   Node *Head = new Node(20);
    Head->next = new Node(30);
    Head->next->next = new Node(40);
    Node *N = new Node(50);
    Head->next->next->next  = N;
    Node *NN = new Node(60);
     N->next  = NN;
     NN->next=Head;



     bool length = findTheLengthOfLoop(Head);

     cout << findTheLengthOfLoop <<endl;


return 0;
}