#include<iostream>
using namespace std;
#include <bits/stdc++.h>

int PS(vector<int> &arr , int i  ,int n,int sum,int target){
    // if(sum == target){
    //     return 1;
    // }
    // if(i ==n && sum != target){
    //     return 0;
    // }
    // if(i==n) return 0;
    // above is only handle for thr greate than 1 

    if(i==n){
        if(sum == target) return 1;
        else return 0;
    }
    // return PS(arr,i+1,arr.size(),sum,target) + PS(arr,i+1,arr.size(),sum+arr[i],target);

    // Note: Answer can be very large, so, output answer modulo 109+7.
    long long ans = PS(arr,i+1,arr.size(),sum,target);
    ans += PS(arr,i+1,arr.size(),sum+arr[i],target);

    ans%=1000000007;
    return ans;

}


int PSM2(int arr[] , int i  ,int n,int sum){
        // if(sum == 0){
        // return 1;
        // }
        // if(i ==n || sum <0){
        // return 0;
        // }

        return PSM2(arr,i+1,n,sum) + PSM2(arr,i+1,n,sum-arr[i]);


}

int main(){
    vector<int> arr = {2,5,6,1};

    cout << PS(arr,0,arr.size(),0,8);


return 0;
}