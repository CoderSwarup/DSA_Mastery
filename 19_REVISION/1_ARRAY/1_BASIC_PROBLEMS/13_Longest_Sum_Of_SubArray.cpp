#include<iostream>
using namespace std;
#include <bits/stdc++.h>


// NOT SOLVE
int longestSubarrayWithSumK(vector<int> arr, int k) {
    // Write your code here
    int start =0;
    int end = 1;
    int count =0;

    while(end<arr.size() && start<arr.size()){
        if(arr[start] + arr[end] == k){
            count = max(count,(end-start+1));
            end++;
        }
        
        if(arr[start] + arr[end] > k){
            count = count;
            start++;
        }
    }

    return count;
    
}
int main(){
vector<int> arr = {1, 2, 3, 1, 1, 1, 1};
cout << longestSubarrayWithSumK(arr, 3);

return 0;
}