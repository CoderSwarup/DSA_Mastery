#include<iostream>
using namespace std;
#include <bits/stdc++.h>

class Stack{
    int *arr;
    int size;
    int top;
    public:

    Stack(int s){
        size=s;
        arr=new int[s];
        top=-1;
    }

    // push operation
    void Push(int val){
        if(top == size-1){
            cout << "Stack is OverFlow" << endl;
            return;
        }
        cout << val << " is push into the Stack"<< endl;
        top++;
        arr[top] = val;
    }

    // POP Operation
    void Pop(){
        if(top == -1){
            cout << "Stack is UnderFlow" << endl;
            return;
        }
        cout << arr[top] << " is pop from the Stack"<< endl;
        top--;
    }

    // Peak operation
    int Peak(){
        if(top == -1){
         cout << "Stack is Empty "<<endl;
         return -1;   
        }

        return arr[top];
    }

    // is Stack empty
    bool isEmpty(){
        if(top == -1){
            return true;
        }else{
            return false;
        }
    }

    // stack size
    int isSize(){
        return top+1;
    }
};

int main(){

    // create a Instance of the stack 
    Stack s(4);

    s.Push(2);
    s.Push(1);
    s.Push(3);
    s.Push(4);
    
    s.Pop();

    cout << "Peak element is : " << s.Peak() << endl;
    cout << "is Stack Empty : " << s.isEmpty() << endl;
    cout << "Size of the Stack : " << s.isSize() << endl;


return 0;
}