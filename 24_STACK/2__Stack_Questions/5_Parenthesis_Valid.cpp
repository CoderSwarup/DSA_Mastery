#include<iostream>
using namespace std;
#include <bits/stdc++.h>


//str = ((())())  //=> valid
//str = ((())))  //=> Not valid

// TC O(n)
// sc O(n)

void CheckStr(string str){
        bool check = true;
    stack<char> s;
    for(int i=0;i<str.size();i++){
        if( str[i] == '('){
            s.push(str[i]);
        }else {
            if(s.empty()){
                check = false;
                break;
            }else{
                s.pop();
            }
        }
    }

    if(check){
        cout << "Stack is Valid";
    }else{
        cout << "Stack is Not Valid";
    }
}

// how to solve using the O(1) Space

void checkStrOptimal(string str){
    int Leftcount =0;
     for(int i=0;i<str.size();i++){
        if(str[i] == '('){
            Leftcount++;
        }else{
            Leftcount--;
        }
         
    }
     if(Leftcount == 0){
        cout << "Stack is Valid";
    }else{
        cout << "Stack is Not Valid";
    }

}
int main(){

    string str = "((())())";
    // CheckStr(str);
    checkStrOptimal(str);

    return 0;
}