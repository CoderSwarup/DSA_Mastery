#include<iostream>
using namespace std;
#include <bits/stdc++.h>


long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        
        for(long long i=0;i<n;i++){
            pq.push(arr[i]);
        }   
        
        long long cost =0;
        while(pq.size() >1){
            long long s1 =pq.top();
            pq.pop();
            long long s2 =pq.top();
            pq.pop();
            
            long long rope = s1+s2;
            cost += rope;
            
            pq.push(rope);
        }
        
        return cost;
}

int main(){

    long long n = 4;
    long long arr[] = {4, 3, 2, 6};

    cout << minCost(arr,n);

return 0;
}