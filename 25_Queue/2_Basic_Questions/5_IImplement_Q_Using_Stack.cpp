#include<iostream>
using namespace std;
#include <bits/stdc++.h>

class Queue{
    stack<int>s1 ; //For Push
    stack<int>s2; //For Pop

    public:

    bool  empty(){
        return s1.empty() && s2.empty();
    }

    void push(int x){
        s1.push(x);
    }


    int pop(){
        if(empty()){
            cout << "Stack is underFlow" <<endl;
            return -1;
        }
        if(!s2.empty()){
            int ele = s2.top();
            s2.pop();
            return ele;
        }else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            int ele = s2.top();
            s2.pop();
            return ele;
        }
    }

    int front(){
        if(empty()){
            cout << "Stack is Empty" <<endl;
            return -1;
        }

        if(!s2.empty()){
            return s2.top();
        }else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
          
        }
    }
};

int main(){

    Queue q;

    q.push(1);
    cout << q.pop() <<  endl;
    cout << q.front() <<  endl;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.front() <<  endl;
    cout << q.pop() <<  endl;
    cout << q.front() <<  endl;
    




return 0;
}