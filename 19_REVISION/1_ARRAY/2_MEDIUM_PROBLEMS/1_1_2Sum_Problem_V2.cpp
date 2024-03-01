#include<iostream>
using namespace std;
#include <bits/stdc++.h>



// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

// TC O(N2)
vector<int> twoSumBruteforce(vector<int>& nums, int target) {
        int length = nums.size();
        vector<int> ans;


        for(int i=0;i<length;i++){
            for(int j=i+1;j<length;j++){
                if(nums[i]+nums[j]==target){
                    ans.push_back(i);
                    ans.push_back(j);
                  
                }
            }
        }
    return ans;
   
    }


vector<int> twoSumBetter(vector<int>& nums, int target) {
        vector<int> ans;

        int n = nums.size();
        map<int, int> hash;
        for (int i = 0; i < n; i++) {
            int requiredElem = target - nums[i];
            if (hash.find(requiredElem) != hash.end()) {
                ans.push_back(hash[requiredElem]);
                ans.push_back(i);
            }
            hash[nums[i]] = i; // store the
        }

        return ans;
   
}


int main(){

    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    // vector<int> ans = twoSumBruteforce(arr,target); 
    vector<int> ans = twoSumBetter(arr,target); 


    for(auto i :ans){
        cout << i << " ";
    }

return 0;
}