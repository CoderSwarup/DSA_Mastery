#include<iostream>
using namespace std;
#include <bits/stdc++.h>


 bool search(vector<int>& nums, int target) {
        
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + ((high - low) / 2);
             if(nums[mid] == target) return true;

             // edge case 
             if(nums[low] == nums[mid]  && nums[mid] == nums[high]){
                // cout<< "COME" <<"\n";
                low += 1;
                high -=1;
                continue;
             }
            // left sorted
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target <= nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if (nums[mid] <= target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return false;
    }
int main(){

    vector<int> arr = {3,3,1,1,3,3};
    cout << search(arr,3);



return 0;
}