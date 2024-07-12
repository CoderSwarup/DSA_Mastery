#include<iostream>
using namespace std;
#include <bits/stdc++.h>


// Brute Force 
// TC O(N3)
vector <int> maxOfMin(int arr[], int n)
{
    // Your code here
    vector<int> ans(n,0);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            int num = INT_MAX;
            for(int k=j;k<j+i+1;k++){
                num = min(num,arr[k]);
            }
            
            ans[i] = max(ans[i],num);
        }
    }
    
    return ans;
}

// TC O(N)
vector <int> maxOfMinBetter(int arr[], int n)
{
    // Your code here
    vector<int> ans(n,0);
    stack<int> s;

     for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] < arr[i]) {
            int index = s.top();
            s.pop();
            if (s.empty()) {
                int range = i;
                ans[range - 1] = max(ans[range - 1], arr[index]);
            } else {
                int range = i - s.top() - 1;
                ans[range - 1] = max(ans[range - 1], arr[index]);
            }
        }
        s.push(i);
    }
    while (!s.empty()) {
        int index = s.top();
        s.pop();
        if (s.empty()) {
            int range = n;
            ans[range - 1] = max(ans[range - 1], arr[index]);
        } else {
            int range = n - s.top() - 1;
            ans[range - 1] = max(ans[range - 1], arr[index]);
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        ans[i] = max(ans[i], ans[i + 1]);
    }

    return ans;
}


vector <int> maxOfMinBetter2(int arr[], int n)
{
       vector<int> ans(n, 0);
    stack<int> s;
    vector<int> left(n, -1), right(n, n);

    // Find the nearest smaller elements on the left
    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        if (!s.empty()) {
            left[i] = s.top();
        }
        s.push(i);
    }

    // Clear the stack for reuse
    while (!s.empty()) s.pop();

    // Find the nearest smaller elements on the right
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        if (!s.empty()) {
            right[i] = s.top();
        }
        s.push(i);
    }

    // Fill ans array with maximum values for each range length
    for (int i = 0; i < n; i++) {
        int len = right[i] - left[i] - 1;
        ans[len - 1] = max(ans[len - 1], arr[i]);
    }

    // Propagate the maximum values backward
    for (int i = n - 2; i >= 0; i--) {
        ans[i] = max(ans[i], ans[i + 1]);
    }

    return ans;
}

int main(){
    int n =7;
    int arr[n] = {10,20,30,50,10,70,30};


//    vector<int> ans = maxOfMin(arr,n);
   vector<int> ans = maxOfMinBetter2(arr,n);
   
   for(int i=0;i<n;i++){
    cout << ans[i] << " "; 
   }


return 0;
}