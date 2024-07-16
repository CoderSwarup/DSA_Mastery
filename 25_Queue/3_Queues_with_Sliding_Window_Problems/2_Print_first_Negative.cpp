#include<iostream>
using namespace std;
#include <bits/stdc++.h>


// TC O(N-K) * O(K)
//SC O(K)

long long int firstNeg( queue<long long int> Q){
    while(!Q.empty()){
        if(Q.front() < 0){
            return Q.front();
        }
        Q.pop();
    }
    
    return 0;
}

vector<long long> printFirstNegativeInteger(
    long long int A[],long long int N, long long int K) {
        
        queue<long long int> Q;
        vector<long long int>ans;
        
        for(long long int i=0; i<K-1;i++){
            Q.push(A[i]);
        }
        
        
        for(long long int i=K-1; i<N;i++){
            Q.push(A[i]);
            ans.push_back(firstNeg(Q));
            Q.pop();
        }
        
        return ans;
                                                 
 }

 // OPTIMAL APPROACH

// O(N)

vector<long long> printFirstNegativeIntegerOptimal(
    long long int A[],long long int N, long long int K) {
        
        queue<long long > Q;
        vector<long long int>ans;
        
        for(long long int i=0; i<K-1;i++){
            if(A[i] <0)
            Q.push(i);
        }
        
        
        for(long long int i=K-1; i<N;i++){
            if(A[i] <0 ){
                Q.push(i);
            }
            
            //check is Q empty
            if(Q.empty()){
                ans.push_back(0);
            }else{
                
                if(Q.front() <= i-K){
                    Q.pop();
                }
                
                if(Q.empty()){
                    ans.push_back(0);
                }else{
                    ans.push_back(A[Q.front()]);
                }
                
            }
           
        }
        
        return ans;
                                                 
 }

int main(){
    long long int A[5] = {-8, 2, 3, -6, 10};
    long long int N =5;
    long long int K = 2;

    // vector<long long> ans = printFirstNegativeInteger(A,N,K);
    vector<long long> ans = printFirstNegativeIntegerOptimal(A,N,K);
    for(long long int i=0; i<ans.size();i++){
        cout<<ans[i]<<" ";
        }



return 0;
}