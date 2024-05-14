#include<iostream>
using namespace std;
#include <bits/stdc++.h>

 int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int ans = INT_MAX;

        while (low <= high) {
            int mid = low + ((high - low) / 2);

            // optimal case // sarch space is already sorted
            if(nums[low] <= nums[high]){
                ans = min(ans,nums[low]);
                break;
            }
            // if above is not use then also get the answer

            // left sort 
            if (nums[low] <= nums[mid]) {
                ans = min(ans, nums[low]);
                low = mid +1;
            } else {
                ans = min(ans,  nums[mid]);
                high = mid-1;
            }
    
        }

        return ans;
    }

int main(){

    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int ans = findMin(arr);
    cout << "The minimum element is: " << ans << "\n";
    return 0;
}
