#include<iostream>
using namespace std;
#include <vector>

// https://leetcode.com/problems/move-zeroes/
void moveZeroes(vector<int>& nums) {
        int nonzero = 0;

        for(int j =0;j<nums.size();j++){
            if(nums[j] != 0){
                swap(nums[j],nums[nonzero]);
                nonzero++;
            }
        }
    }



int main(){

vector<int> arr = {0,1,0,3,12};

moveZeroes(arr);
for(int i=0; i < arr.size();i++){
    cout << arr[i]<< " ";
}


return 0;
}