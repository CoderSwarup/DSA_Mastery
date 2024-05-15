#include<iostream>
using namespace std;
#include <bits/stdc++.h>


// Brute force 
  int findPeakElement(vector<int>& arr) {
        for(int i=0;i<arr.size();i++){

            if((i == 0 || arr[i-1] < arr[i]) && (i == arr.size()-1 ||  arr[i] > arr[i+1])) return i;
        }

        return -1;
    }


// BS
  int findPeakElementBS(vector<int>& nums) {
        int n = nums.size();

        if(n==1) return 0;

        if(nums[0] > nums[1]) return 0;
        if(nums[n-2] < nums[n-1]) return n-1;

        int low = 1;
        int high = n-2;

        while(low <= high){
            int mid = low +((high-low)/2);

            if(nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1]) return mid;
            else if(nums[mid-1] < nums[mid]) low = mid +1;
            else high = mid -1;
        }


        return -1;
    }

int main(){


    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    int ans = findPeakElement(arr);
    // int ans = findPeakElementBS(arr);
    cout << "The peak is at index: " << ans << "\n";
    return 0;
return 0;
}