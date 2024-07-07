#include<iostream>
using namespace std;
#include <bits/stdc++.h>

void Print(vector<int> arr){
    for(int i =0;i<arr.size();i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


void NextGreater(vector<int> arr){
    vector<int> ans(arr.size(),-1);

    for(int i =0;i<arr.size()+arr.size();i++){
        for(int j =i+1;j<arr.size()+arr.size();j++){
            
            if(arr[i%arr.size()] < arr[j%arr.size()]){
                ans[i%arr.size()] = arr[j%arr.size()];
                break;
            }
           
        }
    }

    Print(ans);
}


void NextGreaterUsingStack(vector<int> arr){
    vector<int> ans(arr.size(),-1);
    stack<int>s;
    for(int i =0;i<arr.size()+arr.size();i++){
    
            while(!s.empty() && arr[s.top()] < arr[i%arr.size()]){
                    ans[s.top()] = arr[i%arr.size()];
                    s.pop();
            }
            s.push(i%arr.size());
    }

    Print(ans);
}

int main(){

    vector<int> arr = {6,10,7,4,8,9,4};
    // NextGreater(arr);
    NextGreaterUsingStack(arr);


return 0;
}