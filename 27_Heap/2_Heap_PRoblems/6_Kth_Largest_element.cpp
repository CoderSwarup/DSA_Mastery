#include<iostream>
using namespace std;
#include <bits/stdc++.h>

// TC O(NLog(K))
// SC O(K)
int findKthLargest(vector<int>& nums, int k) {

        // create a Min heap 
        priority_queue<int ,vector<int> ,greater<int> > p;

        for(int i=0;i<k;i++){
            p.push(nums[i]);
        }


        //compare
        for(int i=k;i<nums.size();i++){
            if(nums[i] > p.top()){
                p.pop();
                p.push(nums[i]);
            }
        }


        return p.top();

        // Also solve with quick sort 
        
    }

int main(){
    vector<int> arr ={7 ,10 ,4 ,3 ,20 ,15};
     int k = 3;

     cout << k << " th Largest Element is  "<<findKthLargest(arr,k);


return 0;
}