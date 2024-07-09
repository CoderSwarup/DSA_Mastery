#include<iostream>
using namespace std;
#include <bits/stdc++.h>
void Print(vector<int> arr){
    for(int i =0;i<arr.size();i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector <int> calculateSpan(int price[], int n)
{
   // Your code here
   vector<int> ans(n,1);
   stack<int>s;
   
   for(int i=n-1;i>=0;i--){
       while(!s.empty() && price[s.top()] < price[i]){
           ans[s.top()] = s.top() -i;
           s.pop();
       }
       s.push(i);
   }
   
   
   // For Edge case where the all values in decreasing order it give the ans for all 1;
    while(!s.empty()){
        ans[s.top()] = s.top()+1;
        s.pop();
    }   
    
    return ans;
   
}

int main(){

    int price[7] = {100 ,80 ,60, 70, 60 ,75, 85};

    vector<int> ans = calculateSpan(price,7);

    Print(ans);
return 0;
}