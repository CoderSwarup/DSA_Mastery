#include<iostream>
using namespace std;
#include <bits/stdc++.h>

int WayToSumN(vector<int> &arr,int n,int sum){
    if(sum ==0) return 1;
    if(sum <0) return 0;
    int ans =0;
    for(int index=0;index<n;index++){
        ans += WayToSumN(arr,n,sum-arr[index]);

    }

    return ans;
}

int main(){
    vector<int> arr = {1,5,6};
    cout << WayToSumN(arr,arr.size(),0);


return 0;
}