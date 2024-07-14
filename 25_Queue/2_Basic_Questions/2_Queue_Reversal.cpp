#include<iostream>
using namespace std;
#include <bits/stdc++.h>

int main(){

    queue<int> Q ;
    Q.push(1);
    Q.push(2);
    Q.push(3);
    Q.push(4);
    Q.push(5);

    stack<int> s;
   
    //empty queue
    while(!Q.empty()){
        s.push(Q.front());
        Q.pop();
    }

    //Empty Stack
    while(!s.empty()){
        Q.push(s.top());
        s.pop();
    }
    
     while(!Q.empty()){
        cout << Q.front() << " ";
        Q.pop();
    }

return 0;
}