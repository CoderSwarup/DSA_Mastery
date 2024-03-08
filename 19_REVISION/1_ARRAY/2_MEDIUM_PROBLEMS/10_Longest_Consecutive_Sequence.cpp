#include<iostream>
using namespace std;
#include <bits/stdc++.h>

// TC  O(N*N)
bool linearSearch(vector<int> arr,int ele){
    for(int i=0;i<arr.size();i++){
        if(arr[i] == ele){
            return true;
        }
    }

    return false;

}

int longestSuccessiveElementsBruteForce(vector<int>& nums) {

    int length = INT_MIN;

    for(int i =0;i<nums.size();i++){
        int ele = nums[i];
        int count = 1;

        while(linearSearch(nums,ele+1)){
            count++;
            ele++;
        }
        length = max(length,count);
    }

    return length;
}


// Better Using Sorting 
// TC O(N+N*Log(N))

int longestSuccessiveElementsBetter(vector<int>& nums) {
    int size = nums.size();
    if(size == 0) return 0;

    sort(nums.begin(),nums.end());
    int letestSmall = INT_MIN;
    int currentCount =0;
    int length = INT_MIN;

    for(int i=0;i<size;i++){
        if(nums[i] - 1 == letestSmall){
            currentCount++;
            letestSmall = nums[i];
        }else if(nums[i] != letestSmall){
            currentCount = 1;
            letestSmall = nums[i];
        }

        length = max(length,currentCount);
    }

    return length;
}


// OPTIMA:
// TC O(N) + O(2*N) ~ O(3*N), where N = size of the array.

int longestSuccessiveElementsOptimal(vector<int>& nums) {
    unordered_set<int> record;
    int length = 0;

    for(int i=0;i<nums.size();i++){
        record.insert(nums[i]);
    }

    for(auto i:record){
        if(record.find(i -1) == record.end()){
            int count = 1;

            int ele = i;
            while(record.find(ele +1) != record.end()){
                count++;
                ele++;
            };
            length = max(length,count);

        }

    }

    return length;
}



int main(){
    vector<int> a = {100, 200, 1, 2, 3, 4};
    // cout << longestSuccessiveElementsBruteForce(a);
    // cout << longestSuccessiveElementsBetter(a);
    cout << longestSuccessiveElementsOptimal(a);


return 0;
}