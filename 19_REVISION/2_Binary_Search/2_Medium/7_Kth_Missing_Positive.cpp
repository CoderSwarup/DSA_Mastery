#include<iostream>
using namespace std;
#include <bits/stdc++.h>


// bruteforce 

int findKthPositive(vector<int>& arr, int k) {
        

        // brute Force 
        for(int i=0;i<arr.size();i++){
            if(arr[i] < k) k++;
            else return k;
        }

        return k;
    }


// binary search 
int findKthPositiveBs(vector<int>& arr, int k) {
        

         int low = 0;
        int high = arr.size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            int missing = arr[mid] - (mid + 1);
            if (missing < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }  

        // low +k
        return k + high + 1;
}


int main(){

    vector<int> arr = {2,3,4,7,11};
    int k = 5;

    // cout << findKthPositive(arr,k);
    cout << findKthPositiveBs(arr,k);



return 0;
}