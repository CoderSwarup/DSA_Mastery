#include<iostream>
using namespace std;
#include <bits/stdc++.h>


void PRINTNBITN(int n,vector<string> &ans,string &binary){
    if(binary.size() == n){
       int ones =0;
       int zeros =0;

       for(auto i:binary){
        if(i == '1') ones++;
        else zeros++;

        if(zeros>ones) return;
       }
        ans.push_back(binary);
       return;
    }

    binary.push_back('1');
    PRINTNBITN( n,ans, binary);
    binary.pop_back();
    binary.push_back('0');
    PRINTNBITN( n,ans, binary);
    binary.pop_back();
   


}

int main(){

    int n=2;
    vector<string>ans;
    string binary;

    PRINTNBITN(n,ans,binary);
//    sort(ans.begin(), ans.end(), greater<string>());
    for(auto i:ans){
        cout << i << endl;
    }

return 0;
}