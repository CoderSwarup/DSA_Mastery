#include<iostream>
using namespace std;
#include <algorithm>
#include <vector>


vector<int> nextGreaterPermutation(vector<int> &A) {
    // Write your code here.
    int breakPoint =-1;

    // find the Break point
    for(int i=A.size()-2;i>=0;i--){
        if(A[i]<A[i+1]){
            breakPoint = i;
            break;
        }
    }

    if (breakPoint == -1) {
        // reverse the whole array:
        reverse(A.begin(), A.end());
        return A;
    }

    // swap closest Higher Element
    for (int i = A.size() - 1; i > breakPoint; i--) {
        if(A[i] > A[breakPoint]){
            swap(A[i],A[breakPoint]);
            break;
        }
    }

    reverse(A.begin()+breakPoint+1,A.end());
    return A;
}

int main(){

    vector<int>arr = {2,1,5,4,3,0,0};

    // Using Build in stl Algo

    // next_permutation(arr.begin() ,arr.end());
    // for(auto i :arr){
    //     cout << i << " ";
    // } 

    vector<int>ans = nextGreaterPermutation(arr);
    for(auto i :ans){
        cout << i << " ";
    } 


return 0;
}