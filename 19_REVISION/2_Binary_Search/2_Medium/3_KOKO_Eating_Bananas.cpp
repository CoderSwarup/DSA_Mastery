#include<iostream>
using namespace std;
#include <bits/stdc++.h>

int findMax(vector<int> &v) {
    int maxi = INT_MIN;
    int n = v.size();
    //find the maximum:
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}



int timeRequired(int h, vector<int> arr){
    int time = 0;
    for(int j =0;j<arr.size();j++){
        time += ceil(arr[j]/h);
    }

    return time;
}

//Brute Force Approach


int minimumRateToEatBananas(vector<int> arr , int h ){
    int n = arr.size();
    int maxi = findMax(arr);

    for(int i=1;i<=maxi;i++){
        int time = timeRequired(i,arr);
        if(time <= h){
            return i;
        }
    }
    return maxi;
}


// Brute Force
int minimumRateToEatBananasBruteForce(vector<int> v, int h) {
    int low = 1, high = findMax(v);

    //apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        int totalH = timeRequired( mid,v);
        if (totalH <= h) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return low;
}


int main(){
    vector<int> v = {7, 15, 6, 3};
    int h = 8;
    // int ans = minimumRateToEatBananas(v, h);
    int ans = minimumRateToEatBananasBruteForce(v, h);
    cout << "Koko should eat atleast " << ans << " bananas/hr.\n";
    return 0;


return 0;
}