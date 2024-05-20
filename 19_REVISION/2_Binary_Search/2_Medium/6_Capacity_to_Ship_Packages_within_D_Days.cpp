#include<iostream>
using namespace std;
#include <bits/stdc++.h>


int requireDays(vector<int>& weights, int capacity ,int Totaldays){
    int days = 1;
    int load =0;
    for(int i=0;i<weights.size();i++){
        if(weights[i] + load > capacity){
            days++;
            if(days > Totaldays){
                return days;
            }
            load = weights[i];
        }else{
            load += weights[i];
        }
    }
    return days;
}

// TC O((SUM -MAXI)+! *M)
int shipWithinDaysBF(vector<int>& weights, int days) {
    int maxi = INT_MIN;
    int sum =0;
    int n = weights.size();
    for(int i =0;i<n;i++){
        maxi = max(maxi,weights[i]);
        sum += weights[i];
    }
    for(int i=maxi ; i<=sum;i++){
        if(requireDays(weights,i,days) <= days) return i;
    }
    return sum;
}



// optimal 

// TC O(LogN *M)

int shipWithinDaysBS(vector<int>& weights, int days) {
    int maxi = INT_MIN;
    int sum =0;
    int n = weights.size();
    for(int i =0;i<n;i++){
        maxi = max(maxi,weights[i]);
        sum += weights[i];
    }
    int low = maxi;
    int high = sum;

    while(low <= high ){
        int mid = low + ((high-low) /2);
        if(requireDays(weights,mid,days) <= days) high = mid -1;
        else low = mid + 1;
    }


    return low;
}

int main(){


    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;

    // cout << shipWithinDaysBF(weights,days);
    cout << shipWithinDaysBS(weights,days);
return 0;
}