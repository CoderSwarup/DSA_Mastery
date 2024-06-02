#include<iostream>
using namespace std;
#include <bits/stdc++.h>

//Sum of cubes of N natural numbers using Recursion.


int SumOfCubes(int n){

    if(n==0)
    return 0;
    return (n*n*n) + SumOfCubes(n-1);
}

int NoOfEvenEle(vector<int> arr, int i){

    
}

int main(){

    cout << SumOfCubes(5) << endl;


return 0;
}