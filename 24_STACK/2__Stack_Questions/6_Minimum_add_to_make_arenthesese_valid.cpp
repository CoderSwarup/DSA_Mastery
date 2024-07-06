#include<iostream>
using namespace std;
#include <bits/stdc++.h>


void MinAddToMakeValid(string str){
    int count =0;
    stack<char>s;
      for(int i=0;i<str.size();i++){
        if(str[i] == '('){
            s.push(str[i]);
        }else{
            if(s.empty()){
                count++;
            }else{
                s.pop();
            }
        }
         
    }

    cout << "Total Required " << (s.size() + count)<< endl;
}

int main(){

    string str = "((())";
    MinAddToMakeValid(str);


return 0;
}