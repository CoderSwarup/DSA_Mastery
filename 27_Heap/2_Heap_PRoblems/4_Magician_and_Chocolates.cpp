#include<iostream>
using namespace std;
#include <bits/stdc++.h>


int nchoc(int A, vector<int> B) {
    
    priority_queue<int>p;
    for(int i=0;i<B.size();i++){
        p.push(B[i]);
    }
    
    long long maxChoc = 0;
    
    while(A && (!p.empty())){
        maxChoc += p.top();
        
        if(p.top() /2){
            p.push(p.top() /2);
        }
        
        p.pop();
        A--;
    }
    
    return maxChoc % 1000000007;
}


int main(){
    int n = 5;
    vector<int>  Arr= {2,4,8,6,10};

    cout << nchoc(n,Arr);



return 0;
}