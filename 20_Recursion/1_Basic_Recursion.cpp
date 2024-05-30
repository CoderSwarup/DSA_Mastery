#include<iostream>
using namespace std;
#include <bits/stdc++.h>

void recursionBasic(int n){
    
    // base case 
    if(n==0){
        cout<<"Happy Birthday"<<endl;
        return;
        }

    cout << n << " Days Left to Your Birthday" << endl;

    recursionBasic(n-1);
}


// recursion print 1 to n number with the 

void print1ToN(int n){
    if(n == 1){
        cout << 1 << endl;
        return;
    }

    print1ToN(n-1);
    cout << n << endl;
}

// print 1 to n with extra argument


void print1ToNwithArg(int num ,int N){
    if(N == num){
        cout << num << endl;
        return;
    }

    cout << num << endl;
    print1ToNwithArg(num+1,N);
}



void PrintEven(int num){
    if(num <= 0){
        return ;
    }
    if(num%2 == 1) num--;
    PrintEven(num-2);
    cout << num << endl;
}
int main(){
    // recursionBasic(5);

    cout << endl << "Print 1 to N using Recursion " << endl;
    print1ToN(5);


    cout << endl << "Print 1 to N using Recursion using extra argument " << endl;
    print1ToNwithArg(1,5);

    cout << endl;
    PrintEven(18);

return 0;
}