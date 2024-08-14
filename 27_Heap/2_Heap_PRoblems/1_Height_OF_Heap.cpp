#include<iostream>
using namespace std;
#include <bits/stdc++.h>


 int heapHeight(int N, int arr[]){
        // code here
        if(N==1) return 1;
        
        int height =0;
        
        while(N>1){
            height++;
            N/=2;
        }
        
        return height;
}

int main(){

    int arr[] = {1, 3, 6, 5, 9, 8};
    int n =6;
    cout<<heapHeight(n,arr)<<endl;



return 0;
}