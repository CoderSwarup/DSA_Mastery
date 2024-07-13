#include<iostream>
using namespace std;
#include <bits/stdc++.h>

class Queue{
    int *arr;
    int front , rear;
    int size;

    public:

    Queue(int s){
        arr = new  int[s];
        size = s;
        front = -1;
        rear = -1;
    }


    // is Empty 
    bool isEmpty(){
        return front == -1;
    }

    // isFull
    bool isFull(){
        return rear == size-1;
    }

    // Push 
    void push(int x){
        if(isFull()){
            cout << "Queue is Overflow"<< endl;
            return;
           
        }
        // if queue is empty
        else if(isEmpty()){
            cout << x << " is Push in the Queue" << endl;
            front = rear =0;
            arr[0] = x;
        }
        else{
            cout << x << " is Push in the Queue" << endl;
            rear++;
            arr[rear] = x;
        }
    }


    // Pop the Element 
    void pop(){
        if(isEmpty()){
            cout << "Queue is Underflow" << endl;
            return;
        }else{
            if(rear==front){
                cout << "The " << arr[front] << "  is Poped from the Queue" << endl;
                rear =front =-1;
            }else{
                cout << "The " << arr[front] << "  is Poped from the Queue" << endl;
                front++;
            }
        }
    }

    // front Element
    int frontElement(){
        if(isEmpty()){
            cout << "Queue is Empty" << endl;
            return -1;
        }else{
            return arr[front];
        }
    }
};

int main(){

    Queue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.pop();
    int x = q.frontElement();
    if(!q.isEmpty())
    cout << x << endl;
    q.push(4);
    q.pop();

return 0;
}