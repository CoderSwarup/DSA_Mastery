#include<iostream>
using namespace std;
#include <bits/stdc++.h>

// Variety 1 : , we are given the row number r and the column number c, and we need to find out the element at position (r,c). 
// nCr = n! / (r! * (n-r)!)

// how to find the n and r 
// n = given_row - 1
// r = given_col -1;

long long  nCr(int n,int r){
    long  long res =1;

    for(int i=0;i<r;i++){
        res = res * (n-i); // nimerator calculation 
        res = res / (i+1); // denomirator
    }

    // cout << res << endl;
    return (int)(res);
}



// Variation 2
// Given the row number n. Print the n-th row of Pascal’s triangle.


// brute force 
// O(N*r)

void printNthRow(int n){

    for(int col=1;col<=n;col++){
        cout << nCr(n-1,col-1) << " ";
    }
    
}


// OPTIMAL 
// O(N)

void printNthRowOptimal(int n){
    long long ans =1;
    cout << ans << " ";
    for(int col=1;col<n;col++){
        ans *= (n-col);
        ans /=  col;
        cout << ans  << " ";
    }
    
}




//variey 3 
// Print complete pascal triangle 


// TC (N*N*R)

void PrintPascalTriangle(int n){

    for(int i=1;i<=n;i++) {
        for(int col=1;col<=i;col++){
           cout << nCr(i-1,col-1) << " ";
        }
        cout << endl;

    }
}

// Optimal
// TC O(N2)
void PrintPascalTriangleOptimal(int n){

    for(int i=1;i<=n;i++) {
        long long ans = 1;
        cout << ans << " ";
        for(int col=1;col<i;col++){
            ans *= (i-col);
            ans /= col;
            cout << ans << " ";
        }
        cout << endl;

    }
}

int main(){

    // variety 1
    int row = 5 , col = 3;
    cout << nCr(row-1,col-1) << endl;


    // variety 2
    cout << "\nVariety 2 Print nth Row \n";
    printNthRow(5) ;
    cout << endl;
    printNthRowOptimal(5) ;
    cout << endl;


    //  variety 3
    cout << "\nVariety 3 Print Pascal Triangle Row \n";
    PrintPascalTriangle(5);
        cout << endl;

    PrintPascalTriangleOptimal(5);
        cout << endl;


return 0;
}