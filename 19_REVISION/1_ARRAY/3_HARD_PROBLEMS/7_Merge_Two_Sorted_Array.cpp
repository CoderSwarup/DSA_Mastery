#include<iostream>
using namespace std;
#include <bits/stdc++.h>


// using Extra Space
void MergedTwoSortedArray(vector<int> arr , vector<int> arr1){
    vector<int> ans;

    int lefti =0;
    int righti =0;


    while(lefti < arr.size() && righti<arr1.size()){
         while(arr[lefti] == 0) lefti++;
         while (arr1[righti] == 0) righti++;

        if(arr[lefti] < arr1[righti]){
            ans.push_back(arr[lefti]);
            lefti++;
        }else {
            ans.push_back(arr1[righti]);
            righti++;
        }
    }

    while(lefti < arr.size()){
        if(arr[lefti] == 0){
            lefti++;
        }
        else {
            ans.push_back(arr[lefti++]);
        }
    }
    while(righti < arr1.size()){
        if (arr1[righti] == 0) righti++;
        else ans.push_back(arr1[righti++]);
    }


   for (int i=0;i<ans.size();i++)
        cout << ans[i]<<" ";
}


// using Two Pointer 

void MergedTwoSortedArrayOptimal(vector<int>&arr , vector<int>&arr1){
   

    int lefti =arr.size() -1;
    int righti =0;

    while(lefti>=0 && righti <arr1.size()){
        if(arr[lefti] > arr1[righti] ){
            swap(arr[lefti] , arr1[righti]);
            lefti--;
            righti++;
        }else{
            break;
        }
    }

    sort(arr.begin() , arr.end());
    sort(arr1.begin() , arr1.end());

    for (int i=0;i<arr.size();i++)
        cout << arr[i]<<" ";

    for (int i=0;i<arr1.size();i++)
        cout << arr1[i]<<" ";
    

}

void swapIfGreater(vector<int>& arr1, vector<int>& arr2, int index1 , int index2){
    if(arr1[index1] > arr2[index2]){
        swap(arr1[index1] , arr2[index2]);
    }
    
}


void mergegapMethdod(vector<int>& nums1,  vector<int>& nums2){
    int n = nums1.size();
    int m = nums2.size();
    int len = n + m;

    // Initial gap:
    int gap = (len / 2) + (len % 2);

    while (gap > 0) {
        // Place 2 pointers:
        int left = 0;
        int right = left + gap;
        while (right < len) {
            // case 1: left in arr1[]
            //and right in arr2[]:
            if (left < n && right >= n) {
                swapIfGreater(nums1, nums2, left, right - n);
            }
            // case 2: both pointers in nums2[]:
            else if (left >= n) {
                swapIfGreater(nums2, nums2, left - n, right - n);
            }
            // case 3: both pointers in nums1[]:
            else {
                swapIfGreater(nums1, nums1, left, right);
            }
            left++, right++;
        }
        // break if iteration gap=1 is completed:
        if (gap == 1) break;

        // Otherwise, calculate new gap:
        gap = (gap / 2) + (gap % 2);
    }


    for (int i=0;i<nums1.size();i++)
        cout << nums1[i]<<" ";

    for (int i=0;i<nums2.size();i++)
        cout << nums2[i]<<" ";
}


int main(){

    vector<int> nums1 = {1, 4, 8, 10};
    vector<int> nums2 = {2, 3, 9};

    //  MergedTwoSortedArray(nums1,nums2);
    //  MergedTwoSortedArrayOptimal(nums1,nums2);
     mergegapMethdod(nums1,nums2);
    

return 0;
}