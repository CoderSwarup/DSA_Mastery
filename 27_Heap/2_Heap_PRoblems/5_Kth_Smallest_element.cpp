#include<iostream>
using namespace std;
#include <bits/stdc++.h>

// TC O(NLog(K))
// SC O(K)
int kthSmallest(vector<int> &arr, int k) {
        // code here
        
        // Max Heap 
        priority_queue<int> p;
        
        
        // insert k smallest Element
       
        for(int i=0;i<k;i++){
            p.push(arr[i]);
        }
        
        // check the remaining element 
        for(int i=k;i<arr.size();i++){
            if(p.top() >arr[i]){
                p.pop();
                p.push(arr[i]);
            }
        }
        
        return p.top();
    }

int main(){
    vector<int> arr ={7 ,10 ,4 ,3 ,20 ,15};
     int k = 3;

     cout << k << " th Smallest Element is  "<<kthSmallest(arr,k);


return 0;
}