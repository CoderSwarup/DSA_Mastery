#include<iostream>
using namespace std;
#include <bits/stdc++.h>


// bruteForce
 double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
     
        vector<int> nums;
        int first = 0;
        int second = 0;

        while (first < n1 && second < n2) {
            if (nums1[first] < nums2[second]) {
                nums.push_back(nums1[first]);
                first++;
            } else {
                nums.push_back(nums2[second]);
                second++;
            }
        }

        while (first < n1) {
            nums.push_back(nums1[first]);
            first++;
        }

        while (second < n2) {
            nums.push_back(nums2[second]);
            second++;
        }

        int n = n1 + n2;
        if (n % 2 == 1) {
            return (double)nums[n / 2];
        }

        double median = ((double)nums[n / 2] + (double)nums[(n / 2) - 1]) / 2.0;
        return median;
}

// better without using the extra array 

double findMedianSortedArraysBetter(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();
    int first = 0;
    int second = 0;

    int indexctn = 0;
    int n = n1 + n2;

    int i1 = n / 2;
    int i2 = (n / 2) - 1;

    double iEle1 = -1;
    double iEle2 = -1;

    while (first < n1 && second < n2) {
        if (nums1[first] < nums2[second]) {
            if (indexctn == i1)
                iEle1 = (double)nums1[first];
            if (indexctn == i2)
                iEle2 = (double)nums1[first];
            first++;
        } else {
            if (indexctn == i1)
                iEle1 = (double)nums2[second];
            if (indexctn == i2)
                iEle2 = (double)nums2[second];
            second++;
        }
        indexctn++;
    }

    while (first < n1) {
        if (indexctn == i1)
            iEle1 = (double)nums1[first];
        if (indexctn == i2)
            iEle2 = (double)nums1[first];
        first++;
        indexctn++;
    }

    while (second < n2) {
        if (indexctn == i1)
                iEle1 = (double)nums2[second];
        if (indexctn == i2)
                iEle2 = (double)nums2[second];
        second++;
        indexctn++;
    }

    if (n % 2 == 1) {
        return iEle1;
    }

    double median = (iEle1 + iEle2) / 2.0;
    return median;
}

// Binary Search 
 double findMedianSortedArraysBinarySearch(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        // take the samaller size of array for the low time complexity
        if(n1>n2) return findMedianSortedArrays(nums2,nums1);
        int n = n1+n2;
        int left = (n1+n2+1)/2;

        int low =0;
        int high = n1;

        while(low<=high){
            int mid1 = low +((high-low)/2);
            int mid2 = left - mid1;

            // initilize the l1 l2 r1 r2
            int l1 = INT_MIN , l2 = INT_MIN;
            int r1 = INT_MAX , r2 = INT_MAX;

            if(mid1 < n1) r1 = nums1[mid1];
            if(mid2 < n2) r2 = nums2[mid2];
            if(mid1- 1 >=0 ) l1 = nums1[mid1-1];
            if(mid2- 1 >=0 ) l2 = nums2[mid2-1];



            // chek condition
            if(l1<=r2 && l2 <= r1){
                if(n%2 == 1) return (double)max(l1,l2);
                else return (double)(((double)max(l1,l2)+(double)min(r1,r2)) /2.0);
            }

            else if(l1>r2) high = mid1 -1;
            else low = mid1+1;


        }

        return 0.0;
}


int main(){
    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2};
    // cout << findMedianSortedArrays(nums1, nums2) << endl;
    cout << findMedianSortedArraysBinarySearch(nums1, nums2) << endl;
    return 0;
}