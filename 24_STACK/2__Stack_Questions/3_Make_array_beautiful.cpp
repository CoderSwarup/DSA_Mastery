#include<iostream>
using namespace std;
#include <bits/stdc++.h>

// make an array beautiful
// given array is combination of the neg- and pos+ number
// you want to remove the adjacent if it negative and positive

int main(){
    vector<int> arr = {2,3,5,-4,6,-2,-8,9};
    stack<int>s;

    for(int i=0;i<arr.size();i++){
        if(s.empty()){
            s.push(arr[i]);
        }else{
            if((s.top() >0 && arr[i] <0) || (s.top()<0 && arr[i] >0)){
                s.pop();
            }else{
                s.push(arr[i]);
            }
        }
    }
    vector<int>ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }

    for(int i=ans.size()-1;i>=0;i--){
        cout << ans[i] << endl;
    }


return 0;
}