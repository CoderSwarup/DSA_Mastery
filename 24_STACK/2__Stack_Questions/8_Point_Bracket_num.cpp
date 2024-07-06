#include<iostream>
using namespace std;
#include <bits/stdc++.h>

int main(){
       
    string str = "(a(abc)d(ef))";
    vector<int> ans;
    stack<char>s;
    int count = 0;
    for(int i=0;i<str.size();i++){
        if(str[i] == '('){
            count++;
            s.push(count);
            ans.push_back(count);
        }else if(str[i] == ')'){
            ans.push_back(s.top());
            s.pop();
        }
    }   
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }



return 0;
}