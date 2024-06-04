#include<iostream>
using namespace std;
#include <bits/stdc++.h>

// Time Complexity O(2n)  =>  2n-1 -1
// space COmplexity O(2n * n2)
// space COmplexity O(n )  when we pass the tempp as reference 
void subSequence(vector<int> &arr,int  i,int n,vector<vector<int>> &ans,vector<int> &temp){
    // base case 
    if(i == n){
        ans.push_back(temp);
        return;
    }

    //for NO
     subSequence(arr,i+1,arr.size(),ans,temp);
     temp.push_back(arr[i]);
     subSequence(arr,i+1,arr.size(),ans,temp);
     temp.pop_back();
}


void subSequenceString(string &s,int  i,int n,vector<vector<char>> &ans,vector<char> &temp){
    // base case 
    if(i == n){
        ans.push_back(temp);
        return;
    }

    //for NO
     subSequenceString(s,i+1,s.size(),ans,temp);
     temp.push_back(s[i]);
     subSequenceString(s,i+1,s.size(),ans,temp);
     temp.pop_back();
}
int main(){
    vector<int> arr = {1,2,3};
    vector<vector<int>> ans;
    vector<int> temp;

    subSequence(arr,0,arr.size(),ans,temp);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;

    }

    cout << endl << "For String" << endl;

    string s = "abc";
    vector<vector<char>> anss;
    vector<char> temps;

    subSequenceString(s,0,s.size(),anss,temps);

    for(int i=0;i<anss.size();i++){
        for(int j=0;j<anss[i].size();j++){
            cout << anss[i][j] << " ";
        }
        cout << endl;

    }

return 0;
}