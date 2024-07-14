#include<iostream>
using namespace std;
#include <bits/stdc++.h>

class Stack{
    queue<int>q1;
    queue<int>q2;

    //push element in the elements present the queue
    // pop element from the queue  where element present in the queue

    public:

    bool empty(){
        return q1.empty() && q2.empty();
    }


    void push(int x){
        if(empty()){
            q1.push(x);
        }else if(q1.empty()){
            q2.push(x);
        }else{
            q1.push(x);
        }
    }

    int pop(){
        if(empty()){
            cout<<"Stack is underflow"<<endl;
            return -1;
        }else if(q1.empty()){
            int n = q2.size();
            n--;
            while(n--){
                q1.push(q2.front());
                q2.pop();
            }

            int x = q2.front();
            q2.pop();
            return x;
        }else{
            int n = q1.size();
            n--;
            while(n--){
                q2.push(q1.front());
                q1.pop();
            }

            int x = q1.front();
            q1.pop();
            return x;
        }
    }

    int top(){
        if(empty()){
            cout<<"Stack is empty"<<endl;
            return -1;
        }else if(q1.empty()){
            return q2.back();
        }else{
            return q1.back();
        }
    }

};




int main(){

    Stack s;
    s.push(1);
    cout << s.pop() << endl;
    s.push(1);
    s.push(2);
    cout << s.top() << endl;
    cout << s.pop() << endl;
     cout << s.top() << endl;


return 0;
}