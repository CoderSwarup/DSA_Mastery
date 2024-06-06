#include<iostream>
using namespace std;
#include <bits/stdc++.h>

int PSWithRepeasteElement(vector<int> arr,int i,int n ,int sum){
    if(sum == 0) return 1;

    if(i == n || sum < 0) return 0;

    return PSWithRepeasteElement(arr,i+1,arr.size(),sum) +  PSWithRepeasteElement(arr,arr[i] == 0 ? i+1 :i,arr.size(),sum-arr[i]);
}

int main(){

     vector<int> arr = {0,2,3,4};

     cout << PSWithRepeasteElement(arr,0,arr.size(),6);

return 0;
}