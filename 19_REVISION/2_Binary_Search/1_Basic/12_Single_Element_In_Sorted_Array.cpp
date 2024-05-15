#include<iostream>
using namespace std;
#include <bits/stdc++.h>

// brute force 
int singleNonDuplicate(vector<int> arr){
    int n = arr.size();

    if(n==1) return arr[0];

    for(int i=0;i<n;i++){

        // 
        if(i ==0){
            if(arr[i] != arr[i+1]) return arr[i];
        }else if(i == n-1){
            if(arr[i] != arr[i-1]) return arr[i];
        }else{
            if(arr[i] != arr[i+1] && arr[i] != arr[i-1]) return arr[i];
        }
    }

    return -1;
}


// brute fore xor
int singleNonDuplicateXOR(vector<int> arr){
    int n = arr.size();
    int ans = 0;
    if(n==1) return arr[0];

    for(int i=0;i<n;i++){

        // 
        ans ^= arr[i];
       
    }

    return ans;
}


// Optimal O(LogN)
int singleNonDuplicateBS(vector<int>& arr) {
        int n = arr.size();
        int low = 1;
        int high = n-2;
        if(n==1) return arr[0];
        else if(arr[0] != arr[1]) return arr[0];
        else if(arr[n-1] != arr[n-2] ) return arr[n-1];
        while(low <= high){
            int mid = low +((high -low)/2);

            if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]) return arr[mid];

            //we are in the left:
            if((mid % 2 == 1 && arr[mid] == arr[mid - 1]) || (mid % 2 == 0 && arr[mid] == arr[mid + 1]) ){
                low = mid +1;
            }else{
                high = mid-1;
            }
        }

        return -1;
        
    }

int main(){

    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    // int ans = singleNonDuplicate(arr);
    // int ans = singleNonDuplicateXOR(arr);
    int ans = singleNonDuplicateBS(arr);
    cout << "The single element is: " << ans << "\n";
    return 0;

return 0;
}