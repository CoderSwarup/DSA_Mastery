#include<iostream>
using namespace std;
#include <bits/stdc++.h>

//Factorial 
int Factorial(int n){

    if(n <= 1){
        return 1;
    }

   return n * Factorial(n-1);
}

int fact(int num,int N){

    if(num == N){
        return N;
    }


    return num * fact(num+1,N);
}


int SumOfN(int n){
    if(n <= 1){
        return 1;
    }

   return n + SumOfN(n-1);
}


// void SumOfN2(int n){
//     if(n <= 1){
//         cout << n + (n-1)  << endl;
//         return;
//     }

//    SumOfN2(n-1);
//    cout << n + (n-1) << endl;
// }

int Power(int num,int n){

    if(n == 0){
        return 1;
    }
    // if(n == 1){
    //     return num;
    // }

    return num * Power(num,n-1);
}


int SqSum(int n){
    if(n == 0){
        return 0;
    }

    return (n*n) + SqSum(n-1);
}


int main(){

    cout << Factorial(-3) << endl;
    cout << fact(1,5) << endl;

    cout << SumOfN(6) << endl << endl;

    cout << Power(2,5) << endl;

    cout << SqSum(4) << endl;

return 0;
}