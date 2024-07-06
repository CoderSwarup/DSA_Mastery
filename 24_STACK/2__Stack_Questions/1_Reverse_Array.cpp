#include<iostream>
using namespace std;
#include <bits/stdc++.h>



int main(){

    vector<char> arr= {'h','e','l','l','o'};
    stack<char>s;
    for(int i=0;i<arr.size();i++){
        s.push(arr[i]);
    }

    int i=0;

    while(!s.empty()){
        arr[i++] = s.top();
        s.pop();       
    }


    for(int i=0;i<arr.size();i++){
       cout << arr[i] << " ";
    }


return 0;
}