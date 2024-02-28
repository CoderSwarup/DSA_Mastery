#include<iostream>
using namespace std;
#include <bits/stdc++.h>

// Base
 int missingNumber(vector<int>& nums) {
       int missing = nums.size();
       sort(nums.begin(),nums.end());
       for(int i=0;i<nums.size();i++){
           if(nums[i] != i){
               missing = i;
               return missing;
           }
       }
        
         return missing;
    }

// Brut Force 
// TC O(N2)

int missingNumberBruteForce(vector<int>& nums) {


    for(int i=0;i<nums.size();i++){
        int flag =0;
        for(int j=0;j<nums.size();j++){
            if(i == nums[j] ){
                flag =1;
                break;
            }
        }
        if(flag == 0) return i;
    }

    return 0;
}

// Better Approach
// TC O(N*N)
// SC O(N)
int missingNumberBetter(vector<int>& nums) {


    vector<int> hash(nums.size());

    // find all elements hash
    for(int i=0;i<nums.size();i++){
        hash[nums[i]]++;
    }

    for(int i=0;i<hash.size();i++){
        if(hash[i] == 0){
            return  i;
        }

    }


    return 0;
}

// Optimal 1
// TC O(N+N)

int missingNumberOptimal(vector<int>& nums) {
    int totalSum = (nums.size() *(nums.size() +1))/2;

    int elesum =0;
    for(int i=0;i<nums.size();i++)
    elesum += nums[i];

    return (totalSum -elesum);

}

// Optimal 2
// TC O(N)

int missingNumberOptimal2(vector<int>& nums) {
    int xor1 = 0;
    int xor2 = 0;

    for(int i=0;i<nums.size();i++){
        xor1 ^= i;
        xor2 ^= nums[i];
    }
    cout << xor1 << " " << xor2 << endl;
    xor1 = xor1 ^ nums.size();
    cout << xor1 << " " << xor2;

    int x = 1^2^3^4^5;
    cout << endl << x << endl;
    x ^= 6;
    cout << endl << x << endl;

    return (xor1 ^ xor2);

}
int main(){
    vector<int> arr = {3,4,5,6,0,2};
    // cout << missingNumber(arr);
    // cout << missingNumberBruteForce(arr);
    // cout << missingNumberBetter(arr);
    // cout << missingNumberOptimal(arr);
    cout << missingNumberOptimal2(arr);


return 0;
}