#include<iostream>
using namespace std;
#include <bits/stdc++.h>


int maxProductSubArray(vector<int> arr){

    int maxi = INT_MIN;
    for(int i=0;i<arr.size() ;i++){
        int prod = 1;
        for(int j = i ;j < arr.size() ;j++){
            prod *= arr[j];
            maxi = max(maxi,prod);
        }
    }

    return maxi;
}

// time complexity O(N)
int maxProductSubArrayOptimal(vector<int> arr){
    int maxi = INT_MIN;
    int pre = 1;
    int suff = 1;
    for(int i=0;i<arr.size() ;i++){
        if(pre ==0) pre =1;
        if(suff == 0) suff = 1;

        pre = pre * arr[i];
        suff = suff * arr[arr.size() - i- 1];

        maxi = max(maxi , max(pre , suff));
    }
    return maxi;
}



int main(){

    vector<int> nums = {1,2,-3,0,-4,-5};
    // cout<<"The maximum product subarray: "<<maxProductSubArray(nums);
    cout<<"The maximum product subarray: "<<maxProductSubArrayOptimal(nums);

     vector<int> n = {3,4,-5,8,-12,7,6,-2};


    return 0;

return 0;
}