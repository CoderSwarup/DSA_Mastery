// (MIN)MAX

#include<iostream>
using namespace std;
#include <bits/stdc++.h>
int countCowPlace(int n,int k, vector<int> &stalls , int mindistance){
    
    int countcows =1;
    int LastPlaceCow = stalls[0];
    
    for(int i=0;i<n;i++){
        if(stalls[i] - LastPlaceCow >= mindistance){
            countcows++;
            LastPlaceCow = stalls[i];
        }
    }
    if(countcows >=k) return true;
    else return false;
    
}


// BRUTE FORCE
// O(NLogN) + O(MAX-MIN * N)
int solve(int n, int k, vector<int> &stalls) {

    // Write your code here
    sort(stalls.begin(),stalls.end());
    
    int mini =INT_MAX;
    int maxi = INT_MIN;
    
    for(int i=0;i<n;i++){
        mini = min(stalls[i],mini);
        maxi = max(stalls[i],maxi);
    }
    
    
    int maxDistance = maxi -mini;
    
    for(int i=1;i <=maxDistance;i++){
        if(!countCowPlace(n,k,stalls,i)) return (i-1);
    }
    
    return -1;
}

//
int solveBinarySearch(int n, int k, vector<int> &stalls) {

    // Write your code here
    sort(stalls.begin(),stalls.end());
    
    int mini =INT_MAX;
    int maxi = INT_MIN;
    
    for(int i=0;i<n;i++){
        mini = min(stalls[i],mini);
        maxi = max(stalls[i],maxi);
    }
    int low = 1;

    int high = maxi -mini;

    while(low<=high){
        int mid = low + ((high-low)/2);
        if(countCowPlace(n,k,stalls,mid)) low = mid+1;
        else high = mid -1;
    }
    
   
    
    return high;
}


int main(){

    vector<int> stalls = {1 ,2 ,4 ,8 ,9};
    int cows = 3;
    cout << solve(stalls.size(),cows, stalls) << endl;
    cout << solveBinarySearch(stalls.size(),cows, stalls);

return 0;
}