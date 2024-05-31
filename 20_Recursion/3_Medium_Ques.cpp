#include<iostream>
using namespace std;
#include <bits/stdc++.h>

// Fib Series
int Fib(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    return Fib(n-1) + Fib(n-2);
}


 int climbStairs(int n) {
        if(n==0) return 1;
        if(n==1) return 1;

        return climbStairs(n-1) + climbStairs(n-2);
        
    }



int GCD(int a,int b){
    if(b == 0){
        return a;
    }


    return GCD(b,a%b);

}

int main(){

    cout <<  Fib(5) << endl;

    cout << climbStairs(5) << endl;

    cout <<  GCD(12,18) << endl;


return 0;
}