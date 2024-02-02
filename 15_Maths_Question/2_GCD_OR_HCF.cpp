#include<iostream>
using namespace std;

void gcd(int a, int b)
{
    int ans = 1;
    int Min = min(a, b);
    for (int i = 1; i <= Min; i++) {  // Initialize i to 1
        if (a % i == 0 && b % i == 0) {
            ans = i;
        }
    }
    cout << ans;
}

// Gcd ==> euclidean algorithm

// using Remender  

void GCDRem(int a,int b){
    while(b!=0){
        int rem = a%b;
        a=b;
        b=rem;
    }


    cout << a;
}
int GCD(int a, int b){

    if(a==0){
        return b;
    }

    if(b==0){
        return a;
    }
    while(a!=b){
        if(a>b){
            a = a-b;
        }else{
            b= b-a;
        }
    }

    return a;
}

int main()
{
    gcd(3,7);
    cout<< endl<< GCD(3,7) << endl ;
    GCDRem(3,7);

    return 0;
}
