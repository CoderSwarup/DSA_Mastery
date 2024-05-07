#include<iostream>
using namespace std;
#include <bits/stdc++.h>

// TC O(N3)
int subarraysWithSumKBruteForce(vector < int > a, int b){
    int count = 0;
    for(int i =0;i<a.size() ;i++){
        for (int j=i;j<a.size();j++) {
            int sum = 0;
            for(int k = i;k<=j;k++){
                sum ^= a[k];
            }
            if(sum == b) count++;
        }
    }
    return count;
 
}

// TC O(N2)
int subarraysWithSumKBetter(vector < int > a, int b){
    int count = 0;
    for(int i =0;i<a.size() ;i++){
        int sum = 0;
        for (int j=i;j<a.size();j++) {
            sum ^= a[j];
            if (sum == b)
                count++;
        }
    }
    return count;
 
}

// TC O(N)
int subarraysWithSumKOptimal(vector < int > a, int b) {
    // Write your code here
    int xr = 0;
    map<int,int> c;
    c[xr]++;
    int count =0;

    for(int i = 0; i< a.size() ; i++){
        xr ^= a[i];
        int x = xr ^ b;
        count += c[x];
        c[xr]++;
    }
    return count;
}

int main(){
    vector<int> arr = {1, 2, 3, 2};
    int k = 2;

    int ans = subarraysWithSumKBruteForce(arr, k);
    // int ans = subarraysWithSumKBetter(arr, k);
    // int ans = subarraysWithSumKOptimal(arr, k);

    cout << ans;


return 0;
}