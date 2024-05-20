#include<iostream>
using namespace std;
#include <bits/stdc++.h>

int SumByDivisor(vector<int>& nums , int d){
    int ans =0;
    for(int i=0;i<nums.size();i++){
        ans += ceil((double)nums[i] / (double)d);
    }
    return ans ;
 }

 // brute force 

int smallestDivisorBF(vector<int>& nums, int threshold) {
    int n = nums.size();
    if(n > threshold) return -1;
    int maxi = INT_MIN;

    for(int i=0;i<nums.size();i++){
        maxi = max(maxi,nums[i]);
    }
    for(int i=1;i<maxi;i++){
        if(SumByDivisor(nums,i) <= threshold){
            return i;
        }

    }
    


    return -1;
}
 // OPTIMAL BS 

 // TC O(logn * n)
int smallestDivisorBS(vector<int>& nums, int threshold) {
    
    int n = nums.size();
    if(n > threshold) return -1;
    int maxi = INT_MIN;

    for(int i=0;i<nums.size();i++){
        maxi = max(maxi,nums[i]);
    }
    int low = 1;
    int high = maxi;
    while(low <= high){
        int mid = low + ((high-low)/2);
        if(SumByDivisor(nums,mid) <=threshold){
            high = mid-1;
        }else {
            low = mid+1;
        }
    }
    return low;
}

int main(){
    vector<int> arr= {1,2,5,9};
    int threshold = 6;

    cout << smallestDivisorBF(arr,threshold);
return 0;
}