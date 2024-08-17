#include<iostream>
using namespace std;
#include <bits/stdc++.h>



   void Heapify(vector<int> &arr,int index,int n){
        
        int largest = index;
        int left = 2*index+1;
        int right = 2*index+2;
        
        
        if(left<n && arr[left] > arr[largest]){
            largest =left;
        }
        if(right<n && arr[right] > arr[largest]){
            largest =right;
        }
        
        if(largest != index){
            swap(arr[largest],arr[index]);
        Heapify(arr,largest,n);
        }
        
        
        
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        
        vector<int>ans;
        
        for(int i=0;i<n;i++){
            ans.push_back(a[i]);
        }
         for(int i=0;i<m;i++){
            ans.push_back(b[i]);
        }
        
        for(int i=ans.size()/2-1;i>=0;i--){
            Heapify(ans,i,ans.size());
        }
        
        return ans;
    }

int main(){

    vector<int> a = {10, 5, 6, 2}; 
    vector<int> b = {12, 7, 9};

    vector<int>ans  =mergeHeaps(a,b,a.size(),b.size());


    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

return 0;
}