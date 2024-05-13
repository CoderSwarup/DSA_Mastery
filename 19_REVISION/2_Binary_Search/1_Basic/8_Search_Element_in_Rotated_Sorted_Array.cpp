#include<iostream>
using namespace std;
#include <bits/stdc++.h>

 int search(vector<int>& nums, int target) {
        int ans = -1;
        int low =0;
        int high = nums.size() -1;

        while(low <= high){
            int mid = low + ((high-low)/2);
            if(nums[mid] == target) ans = mid;
            
            // left sorted 
             if(nums[low] <= nums[mid] ){
                if(nums[low] <= target && target <= nums[mid]) high = mid -1;
                else low = mid+1;
            }else{
                // right sortd 
                if(nums[mid] <= target && target <= nums[high]) low = mid +1;
                else high = mid-1;
            }
        }
        
        return ans;
    }

int main(){

    vector<int > nums = {4,5,6,7,0,1,2};
    int t = 0;

    cout << search(nums,t);

return 0;
}