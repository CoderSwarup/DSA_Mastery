#include<iostream>
using namespace std;
#include <bits/stdc++.h>

// brute force 
int removeDuplicatesBRUTE(vector<int> &arr, int n) {
	// Write your code here.
	set<int>UNIQUE;
	for(int i=0;i<n;i++){
		UNIQUE.insert(arr[i]);
	}

	return UNIQUE.size();
}

// optimal 
// SC = O(N)

int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[i] != nums[j]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }


int main(){
    vector<int> arr ={1,2,3,3,4,4};
    cout << removeDuplicatesBRUTE(arr,arr.size()) << endl;

    cout  << removeDuplicates(arr);




return 0;
}