#include<iostream>
using namespace std;


int Factorial(int n){
    int fact = 1;
    while(n!=0){
        fact *= n;
        n--;
    }

    cout << fact << endl; 

    return fact;
}

int Ncr(int n,int r){


    if(n==0 || r==0){
        return 1;
    }

    int ncr = Factorial(n) / (Factorial(r) * Factorial(n-r));
    
    return ncr;
}

int main(){

    int n , r;
    cin >> n >> r;

    int ncr = Ncr(n,r);

    cout << "Ncr is " << ncr;

return 0;
}