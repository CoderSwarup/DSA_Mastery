#include<iostream>
using namespace std;
#include <bits/stdc++.h>

// brute force 
// TC O(N3)

int findAllSubarraysWithGivenSumBruteForce(vector<int> arr,int target){
    int count =0;
    int n = arr.size();

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum = 0;
            for(int k=i;k<=j;k++){
                sum+= arr[k];
            }
            if (sum == target) {
                count++;
            }
        }
    }

    return count;
}


// Better 
// TC O(N2)

int findAllSubarraysWithGivenSumBetter(vector<int> arr,int target){
    int count =0;
    int n = arr.size();

    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum += arr[j];
            if (sum == target) {
                count++;
            }
        }
    }

    return count;
}


// OPTIMAL 
// TC O(N * Log N )

// SC O(N)
int findAllSubarraysWithGivenSumOptimal(vector<int> arr,int target){
    int count =0;
    int n = arr.size();
    unordered_map <int,int> preffix;

    int preffixSum =0;

     preffix[0] = 1; // Setting 0 in the map.

    // store preffix sum 
    for(int i=0;i<n;i++){
        preffixSum+=arr[i];

        int diff = preffixSum - target;


        count += preffix[diff];
        
        preffix[preffixSum]++;
    }


    
  

    return count;


}

int main(){

    vector<int> arr = {3, 1, 2, 4};
    int target = 6;
    // cout << findAllSubarraysWithGivenSumBruteForce(arr,target);
    // cout << findAllSubarraysWithGivenSumBetter(arr,target);
    cout << findAllSubarraysWithGivenSumOptimal(arr,target);
    

return 0;
}