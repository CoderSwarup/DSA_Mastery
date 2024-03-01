#include<iostream>
using namespace std;
#include <bits/stdc++.h>


// Sample Input 1:
// 5 5
// 4 1 2 3 1
// Sample Output 1 :
// YES



// BRUTEFORCE
//TC O(N2)
// SC O(1)

string twoSumBruteForce(vector<int> arr,int target){
    int n = arr.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i] + arr[j] == target){
                return "YES";
            }
        }
    }

    return "NO";
}

// BETTER APPROACH
// using hashing 
// TC O(N+log(N)) //map
// TC O(N2) //ureder map 

// spac Complexity  is O(N) as we are storing elements

string twoSumBetter(vector<int> arr,int target){
    int n = arr.size();
    map<int , int> hash;
    for(int i=0;i<n;i++){
        int requiredElem = target - arr[i];
        if(hash.find(requiredElem) != hash.end()){
            return "YES";
        }
        hash[arr[i]] = i ; // store the
    }

    return "NO";
}


// OPTIMAL APPROACH TWOPOINBTER
// TC  O(N+log(N))
// SC O(1)
string twoSumOptimal(vector<int> arr,int target){
    int n = arr.size();
    //sort arr
    sort(arr.begin(),arr.end());
    int s =0;
    int e = n-1;
    while(s < e ){
        int sum = arr[s] + arr[e];
        if(sum == target){
            return "YES";
        }else if(sum < target){
            s++;
        }else{
            e--;
        }
    }

    return "NO";

}


int main(){

    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    // cout <<  twoSumBruteForce(arr, target);
    // cout <<  twoSumBetter(arr, target);
    cout <<  twoSumOptimal(arr, target);


return 0;
}