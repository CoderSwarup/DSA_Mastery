#include<iostream>
using namespace std;
#include <bits/stdc++.h>


int BookAllocates(int A[] ,int n,int pages){
    int stu = 1;
    int pagesAllocated = 0;
    
    for(int i=0;i<n;i++){
        if(pagesAllocated + A[i] <= pages){
            pagesAllocated += A[i];
        }else{
            stu++;
            pagesAllocated = A[i];
        }
    }
    return stu;
}
//Function to find minimum number of pages.
// Brute Force
//TC O(SUM-M+1) O(N)
int findPages(int A[], int N, int M) {
    //code here
    
    // Base Condition FOr Return -1
  
    if(M>N){
        return -1;
        
    }
    
    
    // find Max 
    int maxi = INT_MIN;
    int sum =0;
     for(int i=0;i<N;i++){
         maxi = max(maxi,A[i]);
         sum += A[i];
     }
        
        
        
    for(int pages=maxi;pages<=sum;pages++){
        if(BookAllocates(A,N,pages) == M){
            return pages;
        }
    }
     
    return -1;
     
}



//TC O(Olog(SUM-M+1)) O(N)
int findPagesBS(int A[], int N, int M) {
    //code here
    
    // Base Condition FOr Return -1
  
    if(M>N){
        return -1;
        
    }
    
    
    // find Max 
    int maxi = INT_MIN;
    int sum =0;
     for(int i=0;i<N;i++){
         maxi = max(maxi,A[i]);
         sum += A[i];
     }
        
        
        
    int l =maxi;
    int h = sum;

    while(l<=h){
        int mid = l + ((h-l)/2);
        if(BookAllocates(A,N,mid) > M){
            l = mid +1;
        }else{
            h = mid-1;
        }
    }
    
    return l;
}
int main(){

    int A[] = {12 ,34 ,67, 90};
    int n = 4;
    int m =2;


    cout << findPagesBS(A,n,m);

return 0;
}