#include<iostream>
using namespace std;
#include <bits/stdc++.h>

class CircularQueue{
    int *arr;
    int front , rear;
    int size;

    public:

    CircularQueue(int s){
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
        return (rear+1)%size == front;
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
            rear = (rear +1)%size;
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
                front = (front+1)%size;
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

    CircularQueue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    q.pop();
    q.push(6);

    int x = q.frontElement();
    if(!q.isEmpty())
    cout << "Front Element is  " << x << endl;


   
return 0;
}