#include<iostream>
using namespace std;
#include <bits/stdc++.h>


// brute force 

// TC O(N2)
// O(N)  // in worst case 

vector<int> superiorElements(vector<int>&a) {
    // Write your code here.
    vector<int> ans;

    for(int i =0;i<a.size();i++){

        bool flag = true;
        for(int j = i+1;j<a.size();j++){
            if(a[i] < a[j]){
                flag = false;
                break;
            }
        }

        if(flag){
            ans.push_back(a[i]);
        }
    }

    sort(ans.begin(),ans.end());
    return ans;
}


// OPTIMAL 
// TC O(N)
vector<int> superiorElementsOptimal(vector<int>&a) {
    // Write your code here.
    vector<int> ans;
    int maxEle = INT_MIN;
    for(int i =a.size()-1;i>= 0;i--){
        if(a[i] > maxEle){
            ans.push_back(a[i]);
            maxEle = max(maxEle,a[i]);
        }
    }

    // sort(ans.begin(),ans.end());
    return ans;
}


int main(){

    vector<int> arr = {10, 22, 12, 3, 0, 6};
    // vector<int> ans = superiorElements(arr);
    vector<int> ans = superiorElementsOptimal(arr);

    for(auto i:ans){
        cout << i << " ";
    }

    return 0;
}