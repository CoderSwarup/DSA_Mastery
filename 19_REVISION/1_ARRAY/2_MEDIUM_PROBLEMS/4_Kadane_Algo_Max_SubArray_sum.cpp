#include<iostream>
using namespace std;
#include <bits/stdc++.h>

// brute force 
int maxSubArrayBruteForce(vector<int>& nums) {
    int maxSum = INT_MIN;
    for(int i=0;i<nums.size();i++){
            int sum =0;
        for(int j=i;j<nums.size();j++){
            sum += nums[j];
            maxSum = max(sum,maxSum);
        }

    }

    return maxSum;
}
int maxSubArrayOptimal(vector<int>& nums) {
        int sum = 0;
        int max = INT_MIN;
        for(int i=0;i<nums.size();i++){

            sum += nums[i];
            if(sum > max){
                max = sum;
            }

            if(sum <0){
                sum = 0;
            }
        }

        return max;
}


int main(){

    vector<int>arr = {-2,1,-3,4,-1,2,1,-5,4};
    // cout << maxSubArrayBruteForce(arr);
    cout << maxSubArrayOptimal(arr);



return 0;
}