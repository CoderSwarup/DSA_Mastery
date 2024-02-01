#include<iostream>
using namespace std;


// Gcd ==> euclidean algorithm
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

void LCM(int a ,int b){
    int d = GCD(a,b);
    int f = a/d;
    int g = b/d;


    int lcm = f*g*d;
    cout << lcm;

    // also using formula 
    
    // int lcmByFormula = a*b / GCD(a,b);
    // cout << lcmByFormula;

}

int main()
{

    LCM(3,7);

    return 0;
}
