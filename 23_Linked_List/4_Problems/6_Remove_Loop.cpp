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
            prev->next = NULL;
            break;
        }else{
            visited[curr] = 1;
            prev = curr;
            curr = curr->next;
        }
        
    }
    
    
}

// Without using the extra space

void removeLoopOptimal(Node* head)
    {
        // code here
        // using slow and the Fas Pointer 
        Node *fast = head;
        Node *slow = head;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow){
                break;
            }
        }
        
        
        if(fast == NULL  || fast->next == NULL){
            return;
        }
        
        
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        
        while(slow->next != fast){
            slow = slow->next;
        }
        
        slow->next = NULL;
    }


// optimal method 2 

void removeLoopOptimalM2(Node* head)
{
    // code here
    // using slow and the Fas Pointer 
    Node *fast = head;
    Node *slow = head;
    
    // detetct the Loop 
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            break;
        }
    }
    
    // if the Loop is not Not recursive
    if(fast == NULL  || fast->next == NULL){
        return;
    }
    
    
    // count the length of the loop
    int count = 1;
    slow = slow->next;
    while(slow!=fast){
        count++;
        slow = slow->next;
    }
    
    
    // move the fast pointer from the slow + to count 
    slow = head;
    fast = head;
    
    while(count--){
        fast= fast->next;
    }
    
    
    // now math the both slow and fast Pointer
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    
    
    // remove the Loop
    
    while(slow->next != fast){
        slow = slow->next;
    }
    slow->next = NULL;
}

int main(){
   Node *Head = new Node(20);
    Head->next = new Node(30);
    Head->next->next = new Node(40);
    Node *N = new Node(50);
    Head->next->next->next  = N;
    Node *NN = new Node(60);
     N->next  = NN;
    //  NN->next=Head;



    //  removeLoop(Head);
    // removeLoopOptimal(Head);
    removeLoopOptimalM2(Head);



    Node *t = Head;
    while(t){
        cout << t->data << " ";
        t = t->next;
    }


return 0;
}