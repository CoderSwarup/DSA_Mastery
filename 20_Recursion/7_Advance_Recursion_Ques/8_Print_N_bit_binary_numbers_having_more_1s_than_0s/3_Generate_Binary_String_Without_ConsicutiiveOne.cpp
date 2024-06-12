#include<iostream>
using namespace std;
#include <bits/stdc++.h>

void GenerateStirng(int n ,vector<string> &ans,string &binary){
    if(binary.size() ==n){
        ans.push_back(binary);
        return;
    }

    binary.push_back('0');
    GenerateStirng(n,ans,binary);
    binary.pop_back();

    if(binary.size() == 0 || binary.back() !='1'  ){

        binary.push_back('1');
        GenerateStirng(n,ans,binary);
        binary.pop_back();
    }
}

int main(){

    int n =4;
    vector<string> ans;
    string binary;

    
    GenerateStirng(n,ans,binary);

    for(auto i:ans){
        cout << i << endl;
    }

return 0;
}   