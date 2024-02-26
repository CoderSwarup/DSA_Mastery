#include<iostream>
using namespace std;
#include <bits/stdc++.h> 
vector<int> rotateArray(vector<int>& arr, int n) {
    // Write your code here.
    int firstEle = arr[0];

    for(int i=1;i<n;i++){
        arr[i-1] = arr[i];

    }

    arr[n-1] = firstEle;

    return arr;
}

int main(){
    vector<int> arr = {1, 2, 35, 4, 5};
    vector<int> ans = rotateArray(arr,arr.size());
     for(int i=0;i<ans.size();i++){
        cout <<  ans[i] << " ";

    }


return 0;
}