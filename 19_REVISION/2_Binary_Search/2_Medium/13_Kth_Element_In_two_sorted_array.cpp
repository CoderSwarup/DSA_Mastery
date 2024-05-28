#include<iostream>
using namespace std;
#include <bits/stdc++.h>

  int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(n>m) kthElement(arr2,arr1,m,n,k);
        int low = max(0,k-m);
        int high = min(k,n);
        int size = n+m;
        int left = k;
        while(low <= high){
            int mid1 = low +  ((high-low)/2);
            int mid2 = left - mid1;
            
            int l1 = INT_MIN , l2 = INT_MIN;
            int r1 = INT_MAX , r2 = INT_MAX;
            if(mid1 < n) r1 = arr1[mid1]; 
            if(mid2 < m) r2 = arr2[mid2];
            if(mid1 -1 >= 0) l1 = arr1[mid1-1];
            if(mid2 -1 >= 0) l2 = arr2[mid2-1];
            
            if(l1<= r2 && l2 <= r1){
                return max(l1,l2);
            }
            
            
            if(l1 > r2) high = mid1-1;
            else low = mid1+1;
        }
        return 0;
    }

int main(){



return 0;
}