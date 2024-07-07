#include<iostream>
using namespace std;
#include <bits/stdc++.h>

void Print(vector<int> arr){
    for(int i =0;i<arr.size();i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

// TC O(N2)
void NextGreater(vector<int> arr){
    vector<int> ans(arr.size(),-1);

    for(int i =0;i<arr.size();i++){
        for(int j =i+1;j<arr.size();j++){
            if(arr[i] < arr[j]){
                ans[i] = arr[j];
                break;
            }
        }
    }

    Print(ans);
}


// TC O(n)
// SC O(n)
void NextGreaterUsingStack(vector<int> arr){
    vector<int> ans(arr.size(),-1);
    stack<int>s;
    for(int i =0;i<arr.size();i++){
    
            while(!s.empty() && arr[s.top()] < arr[i]){
                    ans[s.top()] = arr[i];
                    s.pop();
            }
            s.push(i);
    }

    Print(ans);
}

void NextGreaterUsingStackM2(vector<int> arr){
    vector<int> ans(arr.size(),-1);
    stack<int>s;
    for(int i =arr.size()-1;i>=0;i--){
        while(!s.empty() && arr[s.top()] < arr[i]){
                    s.pop();
         }

        if(!s.empty()){
            ans[i] = arr[s.top()];

        }
        s.push(i);
    }

    Print(ans);
}
int main(){


    vector<int> arr = {8,6,4,7,4,9,10,8,12};
    // NextGreater(arr);
    // NextGreaterUsingStack(arr);
    NextGreaterUsingStackM2(arr);

return 0;
}