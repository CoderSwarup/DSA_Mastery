#include<iostream>
using namespace std;
#include <bits/stdc++.h>


// TC O(N)
int upperbound(vector<int> arr, int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] > x) {
            // lower bound found:
            return i;
        }
    }
    return n;
}

// TC O(log n)

int upperBoundBS(vector<int> arr, int n, int x){
    int ans = n;

    int start = 0;
    int end = n-1;
    while (start <= end) {
        int mid = start + ((end-start)/2);
        if(arr[mid] > x){
            ans = mid;
            end = mid - 1;
        }else{
            start = mid + 1;
            
        }
    }
    return ans;
}

int main(){

    vector<int> arr = {3, 5, 8, 15, 19};
    int n = 5, x = 3;
    // int ind = upperbound(arr, n, x);
    int ind = upperBoundBS(arr, n, x);
    cout << "The Upper bound is the index: " << ind << "\n";
    ind = upper_bound(arr.begin(),arr.end(),x) - arr.begin();
    cout << "The upper bound is the index using cp algo: " << ind << "\n";


return 0;
}