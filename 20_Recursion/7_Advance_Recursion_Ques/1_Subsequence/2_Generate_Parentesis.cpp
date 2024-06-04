#include<iostream>
using namespace std;
#include <bits/stdc++.h>

void parenthesis(int n,int l, int r,  vector<string>  &ans,string &temp){
    if(l+r == 2*n){
        ans.push_back(temp);
        return;
    }

    if(l<n){
        temp.push_back('(');
        parenthesis(n,l+1,r,ans,temp);
        temp.pop_back();
    }

    if(r<l){
        temp.push_back(')');
        parenthesis(n,l,r+1,ans,temp);
        temp.pop_back();
    }
}


int main(){
    vector<string>  ans;
    string temp;
    parenthesis(3,0,0,ans,temp);
  
  for(int i=0;i<ans.size();i++){
    cout<<ans[i] << endl;
  }
  return 0;
}