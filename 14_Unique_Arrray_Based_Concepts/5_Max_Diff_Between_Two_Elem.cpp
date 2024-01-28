#include<iostream>
using namespace std;
#include <vector>
#include <limits.h>

// Brute Force Approach 
// TC = O(n2)
// SC = O(1)
void MaxDiffBruteForce(vector<int> arr){
    int n = arr.size();
    int Ans = INT_MIN;

    for(int i =0 ;i<n-1;i++){
        for(int j = i+1;j<n;j++){
            int Diff = arr[j] - arr[i];
            Ans = max(Ans,Diff);
        }
    }

    cout << Ans;
}


// Using Extra array Suffix Max Technique
// TC O(n)
// SC O(n)

void  MaxDiffSuffixMax(vector<int> arr){
    int n = arr.size();
    int Ans = INT_MIN;
    vector<int> SuffixMax(n);

    SuffixMax[n-1] = arr[n-1];
    for(int i=n-2;i>=0;i--){
        int Max = max(arr[i],SuffixMax[i+1]);
        SuffixMax[i] = Max;
    }

    // Now Check the Max diff
    for(int i =0 ;i<n-1;i++){
        int Diff = abs(SuffixMax[i+1] - arr[i]);
        Ans = max(Ans,Diff);
    }
    // for(auto j:SuffixMax){
    //     cout << j << " ";
    // }

    cout << Ans;
}


// Without Extra Space 
// TC = O(n)
//SC = O(1)
void  MaxDiffOptimal(vector<int> arr){

    int n = arr.size();
    int Ans = INT_MIN;
    int suffixMax = arr[n-1];

    for(int i=n-2;i>=0;i--){
        int Diff = suffixMax - arr[i];
        Ans = max(Ans,Diff);
        suffixMax = max(suffixMax,arr[i]);
    }

    cout << Ans;


} 


int main(){

    vector<int> arr = {9,5,8,12,2,3,7,4};
    // MaxDiffBruteForce(arr);
    // MaxDiffSuffixMax(arr);
    MaxDiffOptimal(arr);


return 0;
}