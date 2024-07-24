#include<iostream>
using namespace std;
#include <bits/stdc++.h>

void Print(vector<int> arr){
    cout << endl;
    for(int i=0;i<arr.size();i++)
    cout << arr[i] << " ";

}

// tc O(N*K)
vector<int> slidingWindowMaxBruteForce(vector<int> arr,int k){
    vector<int> ans;

    for(int i=0;i<=arr.size()-k;i++){
        int Max = INT_MIN;
        for(int j=i;j<i+k;j++){
            Max = max(Max,arr[j]);
        }

        ans.push_back(Max);
    }

    return ans;
}

// Optimal
vector<int> slidingWindowMaxOptimal(vector<int> arr,int k){
    deque<int> d;
    vector<int> ans;

    for(int i=0;i<k-1;i++){
        if(d.empty()){
            d.push_back(i);
        }else{
            while(!d.empty() && arr[i] > arr[d.back()])
            d.pop_back();

            d.push_back(i);
        }
    }

    for(int i=k-1;i<arr.size();i++){
        while(!d.empty() && arr[i] > arr[d.back()])
        d.pop_back();

        d.push_back(i);

        if(d.front() <= i-k){
            d.pop_front();
        }

        ans.push_back(arr[d.front()]);
     
    }
    return ans;
}
int main(){

    vector<int> arr = {4,3,7,5,2,3,1,2,8,7};
    int k =4;

    // vector<int> ans = slidingWindowMaxBruteForce(arr,k);
    vector<int> ans = slidingWindowMaxOptimal(arr,k);
    Print(ans);



return 0;
}