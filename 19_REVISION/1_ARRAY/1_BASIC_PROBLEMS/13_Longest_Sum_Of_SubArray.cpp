#include<iostream>
using namespace std;
#include <bits/stdc++.h>


// BruteForce
// TC nearest to O(n3)
int longestSubarrayWithSumKBruteForce(vector<int> arr, long long k) {
    // Write your code here
    int len =0;
    for (int i=0;i<arr.size();i++){
        for (int j=i;j<arr.size();j++){
            long long sum =0;
            for(int l=i;l<=j;l++){
                sum += arr[l];
            }
            if(sum == k){
                len = max(len,j-i+1);
            }
        }
    }

    return len;
    
}

// brute force 2
// TC O(N2)
int longestSubarrayWithSumKBruteForce2(vector<int> arr, long long k) {
    // Write your code here
    int len =0;
    for (int i=0;i<arr.size();i++){
        
        long long sum =0;
        for (int j=i;j<arr.size();j++){
            sum += arr[j];
            if(sum == k){
                len = max(len,j-i+1);
            }
        }
    }

    return len;
    
}

// Better 
// TC ORDER MAP 
    // O(N*LOG(N))

    // UNORDERD MAP 
    // O(N*1)
    // O(N*M)
// SC O(N)

int longestSubarrayWithSumKBetter(vector<int> arr, long long k) {
    // Write your code here
    int len = 0;
    map<long long , int > preffixSumMap;
    long long sum =0;

    for(int i=0;i<arr.size();i++){

        sum += arr[i];

         if (sum == k) {
            len = max(len, i + 1);
        }


        long long remRequiredElem = sum - k;
        if(preffixSumMap.find(remRequiredElem) != preffixSumMap.end()){
            len = max(len,i - preffixSumMap[remRequiredElem]);
        }

        // edge case for 0 and 1 
        if(preffixSumMap.find(sum) == preffixSumMap.end())
        preffixSumMap[sum] = i;
    }
   

    return len;
    
}


// OPTIMAL 

// TC Overall O(n2)
// but Max time O(2n) Because the inner while loop not run every time 
// SC O(1)

int longestSubarrayWithSumKOptimal(vector<int> arr, long long  k) {
    // Write your code here
    int start =0;
    int end = 0;
    int len =0;
    long long sum = arr[0];

    while(end<arr.size() && start<arr.size()){
        while(start < arr.size() && sum > k){
            sum -= arr[start];
            start++;
        }
        if(sum == k){
            len = max(len,end-start+1);
        }


        end++;
        if(end < arr.size()){
            sum += arr[end];
        }
    }

    return len;
    
}

int main(){
// vector<int> arr = {1, 2, 3,1,1,1,1,2};
vector<int> arr = {2,0,0,3};
// cout << longestSubarrayWithSumKBruteForce(arr, 3);
// cout << longestSubarrayWithSumKBruteForce2(arr, 3);
// cout << longestSubarrayWithSumKBetter(arr, 3);
cout << longestSubarrayWithSumKOptimal(arr, 3);

return 0;
}