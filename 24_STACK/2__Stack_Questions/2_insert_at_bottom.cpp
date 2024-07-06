#include<iostream>
using namespace std;
#include <bits/stdc++.h>

// TC O(N)
int main(){ 
     stack<int>s;
     s.push(1);
     s.push(2);
     s.push(3);
     s.push(4);

    int x = 10;

    stack<int> st;

    while(!s.empty()){
        st.push(s.top());
        s.pop();
    }

    s.push(x);
    while(!st.empty()){
        s.push(st.top());
        st.pop();
    }

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }


return 0;
}