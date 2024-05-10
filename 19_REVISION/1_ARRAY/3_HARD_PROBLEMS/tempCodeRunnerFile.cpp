#include<iostream>
using namespace std;
#include <bits/stdc++.h>


// Brute Force 
// Time Complexity 
// O(N2)


vector<int> RepeatingMissingNum(vector<int>arr){
    int repeat =-1;
    int miss = -1;

    for(int i= 1 ; i<= arr.size() ;i++){
        int count =0;

        for(int j= 0 ; j< arr.size() ;j++){
            if (arr[j] == i ) count++;
        }

        if(count == 2) repeat = i;
        else if(count == 0) miss = i;
        
        if(repeat != -1 && miss != -1) break;
    }

    return {repeat , miss};
}


// using hashing 

// TC O(N)
vector<int> RepeatingMissingNumHashing(vector<int>arr){
    int repeat =-1;
    int miss = -1;
    vector<int> ans(arr.size());

    for(int i= 0 ; i< arr.size() ;i++){
        ans[arr[i-1]]++;

        if(ans[arr[i-1]] == 2) repeat = arr[i-1];
        else if(ans[arr[i-1]] == 0) miss = arr[i-1];
     
        
        if(repeat != -1 && miss != -1) break;
    }

    return {repeat , miss};
}

int main(){

    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    // vector<int> ans = RepeatingMissingNum(a);
    vector<int> ans = RepeatingMissingNumHashing(a);
    cout << "The repeating and missing numbers are: {"
         << ans[0] << ", " << ans[1] << "}\n";
return 0;
}