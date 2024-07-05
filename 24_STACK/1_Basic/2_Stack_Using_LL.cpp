#include<iostream>
using namespace std;
#include <bits/stdc++.h>

class Node{
    public:
    int data;
    Node *next;

    Node(int val){
        data = val;
        next = NULL;
    }
};


class Stack{
    Node *top;
    int size;

    public:

    Stack(){
        top = NULL;
        size = 0;
    }

    void Push(int val){
        Node *temp = new Node(val);
        
        // is heap (Dynamic Memory Ram is full)
        if(!temp){
            cout<<"Heap is full"<<endl;
            return;
        }
         cout << val << " is push into the Stack"<< endl;
        temp->next = top;
        top = temp;
        size++;
    }

    void Pop(){
        if(top == NULL){
            cout<<"Stack is empty"<<endl;
            return;
        }
        Node *temp = top;
        cout << temp->data << " is pop from the Stack"<< endl;
        top = top->next;
        delete temp;
    }


    int Peak(){
        if(top == NULL){
            cout<<"Stack is empty"<<endl;
            return -1;
        }

        return top->data;
    }

    bool isEmpty(){
        return top == NULL;
    }

    int isSize(){
        return size;
    }
};

int main(){
    Stack s;
    
    s.Push(1);
    s.Push(2);
    s.Push(3);
    s.Push(4);

    s.Pop();

    cout << "Stack Peak Element is " << s.Peak() << endl;


return 0;
}