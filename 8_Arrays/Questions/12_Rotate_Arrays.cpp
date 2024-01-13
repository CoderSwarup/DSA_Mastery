#include<iostream>
using namespace std;
#include <vector>

//https://leetcode.com/problems/rotate-array/
void rotate(vector<int>& nums, int k) {
        vector<int> temp(nums.size());

        for(int i =0;i<nums.size();i++){
            temp[ (i+k)%nums.size()] = nums[i];
        }

        nums = temp;
}


int main(){

    vector<int> arr = {1,2,3,4,5};
    rotate(arr,4);

    for(int i=0; i < arr.size();i++){
    cout << arr[i]<< " ";
    }

return 0;
}