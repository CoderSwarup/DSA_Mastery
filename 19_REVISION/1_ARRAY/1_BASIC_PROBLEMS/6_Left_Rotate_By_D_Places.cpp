#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>

// Brute force
// sC O(n)
// TC O(N)
vector<int> Rotatetoleft(vector<int> &arr,int n, int k){
    vector<int>temp;
    if (n == 0)
        return temp;

    k = k%n;

    // Push the All from k to n index value in the temp 
    for(int i=k;i<n;i++){
        temp.push_back(arr[i]);
    }

    // Not shoifting position index value push back in the temp
    for(int i=0;i<k;i++){
        temp.push_back(arr[i]);
    }

    return temp;
}

// Brute force2 
// sC O(k) 
// TC O(N+k)

vector<int> Rotatetoleft2(vector<int> &arr,int n, int k){
    vector<int>temp(k);
    if (n == 0)
        return temp;

    k = k%n;

    // Push the All from 0 to k in the temp 
    for(int i=0;i<k;i++){
        temp[i] = arr[i]; 
    }

    // shft Array element by k to n
    for(int i=k;i<n;i++){
        arr[i-k] = arr[i];
    }

    // now put all tamp value in arr at from The remaining pos 
    for(int i=0;i<k;i++){
        arr[n-k+i] = temp[i] ;
    }



    

    return arr;
}


// OPTIMAL
// TC O(2N)
vector<int> leftRotateOptimal(vector<int> arr, int k) {
    int n = arr.size();
    k %= n;
    reverse(arr.begin(), arr.begin() + k);  // reverse  first k elements
    reverse(arr.begin() + k, arr.end()); // reverse k to end
    reverse(arr.begin(), arr.end()); // reverse whole 
    return arr;
}


int main(){


  vector<int>arr = {1, 2, 3, 4, 5, 6, 7};
  int k = 2;
//   vector<int>ans= Rotatetoleft(arr, arr.size(), k);
//   vector<int>ans= Rotatetoleft2(arr, arr.size(), k);
    vector<int>ans= leftRotateOptimal(arr, k);

   for (int i = 0; i <  ans.size(); i++)
   {
    cout << ans[i] << " ";
    }


return 0;
}