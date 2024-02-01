#include "bits/stdc++.h"
#include<iostream>
using namespace std;

const long long N = 1e5+2, MOD = 1e9+7;

int power( long long a,  long long n){
    // If a is greater than MOD 
    a = a % MOD;

    int ans = 1;

    while(n > 0){
        if(n & 1){ //   odd
            ans = (ans * a) % MOD;
        }

        a = (a * a) % MOD;
        n = n >> 1;
    }

    return ans;
}

int main(){
     long long a, n;
    cout << "Enter base (a): ";
    cin >> a;
    
    cout << "Enter exponent (n): ";
    cin >> n;
    
    cout << "Result: " << power(a, n) << endl;
    
    return 0;
}
