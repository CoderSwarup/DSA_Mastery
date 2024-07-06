#include<iostream>
using namespace std;
#include <bits/stdc++.h>

int main(){
    string str = "[{]}{}";

    stack<char>s;
    bool check = true;

    for(int i=0;i<str.size();i++){
        if(str[i] == '{' || str[i] == '[' || str[i] == '(')
        s.push(str[i]);
        else{
            if(s.empty()){
                check = false;
                break;
            }else if(str[i] == ')'){
                if(s.top() == '('){
                    s.pop();
                }else{
                    check = false;
                    break;
                }
            }else if(str[i] == ']'){
                if(s.top() == '['){
                    s.pop();
                }else{
                    check = false;
                    break;
                }
            }else {
                if(s.top() == '{'){
                    s.pop();
                }else{
                    check = false;
                    break;
                }
            }
        }
    }


    if(check == true && s.empty()){
        cout << "Valid Parentheses"<<endl;
    }else{
        cout << "InValid Parentheses"<<endl;
    }

return 0;
}