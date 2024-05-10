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
    vector<int> ans(arr.size(),0);
    for(int i= 0 ; i<arr.size() ;i++){
        ans[arr[i]-1]++;

        
    }

    for(int i= 0 ; i<ans.size() ;i++){
      if(ans[i] == 2) repeat = i+1;
        else if(ans[i] == 0) miss = i+1;
     
        
        if(repeat != -1 && miss != -1) break;
    }

    return {repeat , miss};
}


/// OPTIMAL

// using The MATHS  EQUATION

vector<int> RepeatingMissingNumOptimal1(vector<int>arr){

    int n = arr.size();

    // sum of n natural numbers 
    long long SN = (n*(n+1))/2;
    // sun of n naturals suare numbers 
    long long SN2 = (n*(n+1) * (2*n +1))/6;

    // sum of all elem
    long long S =0;
    // squre sum of all eleme
    long long S2 =0;
    for(int i= 0;i<n;i++){
        S += (long long)arr[i];
        S2 += (long long)arr[i] * (long long)arr[i] ; 
    }

    // equation 1
    long long EQ1 = S - SN;   // x-y
    // equation 2
    long long EQ2 = S2 - SN2; // x2 - y2   ... (x-y)(x+y)

    EQ2 = EQ2 / EQ1; // x+y

    long long x = (EQ1 + EQ2) /2;// .... x-y = eq1
                                //      +x+y = e2
                                //       
                                //       2x = eq1 + eq2 
                                //       x = (eq1 + eq2)/2


    long long y = x-EQ1;  // ..... (x-y) = q1
                         //          y = x - q1

    return {(int)x , (int)y};
}
int main(){

    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    // vector<int> ans = RepeatingMissingNum(a);
    // vector<int> ans = RepeatingMissingNumHashing(a);
    vector<int> ans = RepeatingMissingNumOptimal1(a);
    cout << "The repeating and missing numbers are: {"
         << ans[0] << ", " << ans[1] << "}\n";
return 0;
}