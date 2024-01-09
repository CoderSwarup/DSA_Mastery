#include<iostream>
using namespace std;
// #include <vector>
#include <bits/stdc++.h>

// https://www.codingninjas.com/studio/problems/aggressive-cows_1082559?leftPanelTabValue=PROBLEM

// App
int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(),stalls.end());

    int n = stalls.size();
    int ans = -1;
    int s = 1;
    int e = stalls[n-1] - stalls[0];
    int mid;

    while(s<=e){
        mid = s + (e-s)/2;

        int cowsCount = 1;
        int CowsPosition = stalls[0];

        for(int i=0;i < n;i++){
            if(CowsPosition+mid <= stalls[i]){
                cowsCount++;
                CowsPosition = stalls[i];
            }
        }

        if(cowsCount < k){
            e= mid-1;
        }else{
            ans = mid;
            s = mid+1;
        }
    }

    return ans;
}
int main(){

    vector<int> stalls ={0 ,3 ,4 ,7 ,10 ,9};
    int cows = 4;

   cout <<  aggressiveCows(stalls,cows);

return 0;
}