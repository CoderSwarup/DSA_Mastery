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

 
bool isVisited(vector<Node*> &visitedArray,Node* curr){
    
    for(int i=0;i<visitedArray.size();i++){
        if(visitedArray[i] == curr) return 1;
    }
    
    return 0;
}

// TLE
// TC O(N2)
bool detectLoop(Node* head)
{
    // your code here
    vector<Node*> visitedListAddress;
    Node *curr = head;
    
    while(curr){
        if(isVisited(visitedListAddress,curr)){
            return 1;
        }else{
        visitedListAddress.push_back(curr);
        curr = curr->next;
        }
    }
    
    return 0;
}


// better 

// using Map
// TC = O(N)
// SC = O(N)
bool detectLoopBetter(Node* head)
{
    // your code here
    unordered_map<Node*,int>  visitedListAddress;

    Node *curr = head;
    
    while(curr){
        if(visitedListAddress[curr] == 1){
            return 1;
        }else{
        visitedListAddress[curr] =1;
        curr = curr->next;
        }
    }
    
    return 0;
}

// Optima
// using slow and fast pointer
// TC = O(N)
// SC = O(1)
bool detectLoopOptimal(Node* head)
{
    // your code here

    Node *fast = head;
    Node *slow = head;

    
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;

        if(slow == fast){
            return 1;
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


    //  bool isLoop = detectLoop(Head);
    //  bool isLoop = detectLoopBetter(Head);
     bool isLoop = detectLoopOptimal(Head);

     cout << isLoop <<endl;


return 0;
}