#include<iostream>
using namespace std;
#include <bits/stdc++.h>

int main(){
    vector<int> arr = {2,1,3,4,5};
    stack<int>minElem;

    for(int i=0;i<arr.size();i++){
        if(minElem.empty()){
            minElem.push(arr[i]);
        }else{
            if(arr[i] < minElem.top()){
                 minElem.push(arr[i]);
            }else{
                 minElem.push(minElem.top());
            }
        }
    }


    while(!minElem.empty()){
        cout<<minElem.top()<<" ";
        minElem.pop();

    }

return 0;
}