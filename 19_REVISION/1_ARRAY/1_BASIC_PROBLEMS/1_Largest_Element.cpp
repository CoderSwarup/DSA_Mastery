#include<iostream>
using namespace std;
#include <bits/stdc++.h> 
#include <vector>
int largestElement(vector<int> &arr) {
    // Write your code here.
    int max = INT_MIN;
    for(int i=0;i<arr.size();i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

int main(){
    vector<int> arr = {2,5,1,3,0};
    cout << "The largest element in the array : " << largestElement(arr);


return 0;
}