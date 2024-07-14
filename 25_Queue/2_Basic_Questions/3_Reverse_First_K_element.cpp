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


    int k=3;
    stack<int> s;

    while(k--){
        s.push(Q.front());
        Q.pop();
    }

    int n = Q.size();

    while(!s.empty()){
        Q.push(s.top());
        s.pop();
    }

    while(n--){
        Q.push(Q.front());
        Q.pop();
    }

    while(!Q.empty()){
        cout << Q.front() << " ";
        Q.pop();
    }

return 0;
}