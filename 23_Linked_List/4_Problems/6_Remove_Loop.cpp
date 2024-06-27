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

 
void removeLoop(Node* head)
{
    // code here
    unordered_map<Node*,int> visited;
    Node *curr = head;
    // just remove the loop without losing any nodes
    Node *prev = NULL;
    while(curr){
        if(visited[curr] ==1){
            cout << prev->data << endl;
            prev->next = NULL;
            break;
        }else{
            visited[curr] = 1;
            prev = curr;
            curr = curr->next;
        }
        
    }
    
    
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



     removeLoop(Head);



    Node *t = Head;
    while(t){
        cout << t->data << " ";
        t = t->next;
    }


return 0;
}