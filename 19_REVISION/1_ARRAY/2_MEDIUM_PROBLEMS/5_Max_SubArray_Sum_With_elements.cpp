#include<iostream>
using namespace std;
#include <bits/stdc++.h>


vector<int> maxSubArrayWithElements(vector<int>& nums) {
        int sum = 0;
        int max = INT_MIN;
        int startIndex =-1;
        int endIndex = -1;

        for(int i=0;i<nums.size();i++){
            if(sum == 0) startIndex = i;
            sum += nums[i];
            if(sum > max){
                max = sum;
           
                endIndex =i;
            }

            if(sum <0){
                sum = 0;
            }
        }

        // 
        vector<int> ans ;
        for(int i= startIndex;i<=endIndex;i++){
            ans.push_back(nums[i]);
        }

        return ans;
}


int main(){

    vector<int>arr = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int>ans = maxSubArrayWithElements(arr);

    for(auto i:ans){
        cout << i << " ";
    }



return 0;
}