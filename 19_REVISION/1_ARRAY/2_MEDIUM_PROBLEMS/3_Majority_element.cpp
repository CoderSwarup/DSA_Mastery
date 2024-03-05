#include<iostream>
using namespace std;
#include <bits/stdc++.h>

// TC O(N2)

int majorityElementBruteForce(vector<int>& nums) {
    
    for(int i=0;i<nums.size();i++){
        int count =0;
        for(int j=0;j<nums.size();j++){
            if(nums[i] == nums[j]){
                count++;
            }
        }

        if(count > (nums.size()/2)){
            return nums[i];
        }
    }

    return -1;
       
}

//Hashing 
// TC O(N*Log(N))
// SC O(N)
int majorityElementBetter(vector<int>& nums) {
    
    map<int ,int>hash;

    // count 
    for(int i=0;i<nums.size();i++){
        hash[nums[i]]++;
    }


    for(auto  it : hash){
        if(it.second > (nums.size()/2)){
            return it.first;
        }
    }
    return -1;
       
}



// optimal 
// TC O(N)

int majorityElementOptimal(vector<int>& nums) {
    
    int count = 0;
    int ele = nums[0];

    for(int i=0;i<nums.size();i++){
        if(count == 0){
            count++;
            ele = nums[i];
        }else if(ele == nums[i]){
            count++;
        }else{
            count--;
        }
    }

    

    // 
    int isThatEleCount = 0;
    for(int i=0;i<nums.size();i++){
        if(ele == nums[i]){
            isThatEleCount++;
        }
    }

    if(isThatEleCount > (nums.size()/2)){
        return ele;
    }
    return -1;
       
}




int main(){

    // vector<int> arr = {2,2,1,1,1,2,2};
    vector<int> arr = {3,2,3};
    // cout << majorityElementBruteForce(arr);
    // cout << majorityElementBetter(arr);
    cout << majorityElementOptimal(arr);

return 0;
}