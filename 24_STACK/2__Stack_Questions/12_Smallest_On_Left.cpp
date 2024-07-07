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
void LeftSmallest(vector<int> arr){
    vector<int> ans(arr.size(),-1);

    for(int i =0;i<arr.size();i++){
        for(int j =i-1;j>=0;j--){
            if(arr[j] < arr[i]){
                ans[i] = arr[j];
                break;
            }
            
        }
    }

    Print(ans);
}


// TC O(n)
// SC O(n)
void LeftSmallestUsingStack(vector<int> arr){
    vector<int> ans(arr.size(),-1);
    stack<int>s;
    for(int i=arr.size();i>=0;i--){
        while(!s.empty() && arr[s.top()] > arr[i]){
            ans[s.top()] = arr[i];
            s.pop();
        }
            s.push(i);
    }

    Print(ans);
}

int main(){

     vector<int> arr = {4,13,11,5,9,7,8,6};
    //  LeftSmallest(arr);
     LeftSmallestUsingStack(arr);



return 0;
}