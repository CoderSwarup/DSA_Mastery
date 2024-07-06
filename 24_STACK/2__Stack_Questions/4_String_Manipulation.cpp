#include<iostream>
using namespace std;
#include <bits/stdc++.h>

int main(){

    vector<string> arr = {"ab","ac","da","da","ac","db","ea"};
    
    stack<string>s;
       for(int i=0;i<arr.size();i++){
        if(s.empty()){
            s.push(arr[i]);
        }else{
            if(s.top() == arr[i]){
                s.pop();
            }else{
                s.push(arr[i]);
            }
        }
    }


    vector<string>ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }

    for(int i=ans.size()-1;i>=0;i--){
        cout << ans[i] << endl;
    }

return 0;
}