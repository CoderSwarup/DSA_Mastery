#include<iostream>
using namespace std;
#include <bits/stdc++.h>


void PRINTNBITN(int n,vector<string> &ans,string &binary,int zeros ,int ones){
    if(binary.size() == n){
        ans.push_back(binary);
       return;
    }

    binary.push_back('1');
    PRINTNBITN( n,ans, binary,zeros,ones+1);
    binary.pop_back();

    if(zeros<ones){
        binary.push_back('0');
        PRINTNBITN( n,ans, binary,zeros+1,ones);
        binary.pop_back();
    }
   


}

int main(){

    int n=2;
    vector<string>ans;
    string binary;

    PRINTNBITN(n,ans,binary,0,0);
    for(auto i:ans){
        cout << i << endl;
    }

return 0;
}