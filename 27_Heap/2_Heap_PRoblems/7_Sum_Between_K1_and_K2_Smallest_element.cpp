#include<iostream>
using namespace std;
#include <bits/stdc++.h>
 long long sumBetweenTwoKth( vector<long long> &A, long long N, long long K1, long long K2)
    {
        // Your code goes here
        
        // Create a Max heap
        priority_queue<long long> p1;
        priority_queue<long long> p2;
        
        
          // insert K1 smallest Element
       
        for(long long i=0;i<K1;i++){
            p1.push(A[i]);
        }
          // insert K2-1 smallest Element
       
        for(long long i=0;i<K2-1;i++){
            p2.push(A[i]);
        }
        
        //find k1 smallest element
        for(long long i=K1;i<N;i++){
            if(A[i] < p1.top()){
                p1.pop();
                p1.push(A[i]);
            }
        }
        
        //find k2-1 smallest element
        for(long long i=K2-1;i<N;i++){
            if(A[i] < p2.top()){
                p2.pop();
                p2.push(A[i]);
            }
        }
        
        //find sum 
        long long sum1 =0;
        long long sum2 =0;
        
        while(!p1.empty()){
            sum1+= p1.top();
            p1.pop();
        }
        
        
        while(!p2.empty()){
            sum2+= p2.top();
            p2.pop();
        }
        
        
        return sum2-sum1;
    }


int main(){
    vector<long long> arr = {20, 8, 22, 4, 12, 10, 14};
     int k1 = 3;
     int k2 = 6;

     cout << "Sum  between " << k1 << " th smallest element and " << k2 << " th smallest element is : " <<  sumBetweenTwoKth(arr,arr.size(),k1,k2);


return 0;
}