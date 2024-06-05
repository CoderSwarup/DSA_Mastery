#include<iostream>
using namespace std;
#include <bits/stdc++.h>

// TC => (2n) => O(2n+1 -1)
// spcae Complexity O(n)
bool targetSum(vector<int> &arr,int i,int n, int target){
    if(target == 0) return true;
    if(i== n || target <0) return false;

    return targetSum(arr,i+1,arr.size(),target) || targetSum(arr,i+1,arr.size(),target-arr[i]);
}

int main(){
    vector<int> arr = {1,2,3};
    int target = 51;
    cout << targetSum(arr,0,arr.size(),target);


return 0;
}