#include<iostream>
using namespace std;
#include <bits/stdc++.h>


class Node{
    public:
    int data;
    Node *next;

    Node(int x){
        data =x;
        next = NULL;
    }
};


class Queue{
    Node *front;
    Node *rear;

    public:

    Queue(){
        front = NULL;
        rear = NULL;
    }


    bool isEmpty(){
        return front == NULL;
    }

    void push(int x){
        if(isEmpty()){
            Node *temp = new Node(x);
            front = temp;
            rear = temp;
            cout << x << " is push into The queue"<< endl;
            return;
        }else{
            rear->next = new Node(x);
            rear = rear->next;
            cout << x << " is push into The queue"<< endl;
        }
    }

    void pop(){
        if(isEmpty()){
            cout << "Queue is UnderFlow"<< endl;
            return;
        }else{
            Node *temp = front;
            front = front->next;
            cout << "The element " << temp->data << "  is pop from the queue"<< endl;
            delete temp;
        }
    }


    void frontElement(){
        if(isEmpty()){
            cout << "Queue is Empty"<< endl;
            return;
        }else{
            cout << "The front element is " << front->data << endl;
        }
    }
};

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.pop();

    q.frontElement();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.frontElement();


return 0;
}