#include<iostream>
using namespace std;


// Remeber that if we nedd to default any argument  to a function, we should put it at the end of the argument list.
// Ex 
// void defaultArg(int n=6,int m){} // its wrong
// void defaultArg(int n,int m=78){} // correct 
void defaultArg(int n=8,int m=78){
    cout <<  n << " " << m << endl;
}

int main(){

    int n =0;
    int m = 1l;

    defaultArg(n,m); 
    defaultArg();


return 0;
}