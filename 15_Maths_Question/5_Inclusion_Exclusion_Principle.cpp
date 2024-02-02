#include<iostream>
using namespace std;


int Divisible(int n,int a,int b){
    int c1 = n/a;
    int c2 = n/b;

    int IntesectNum = n/(a*b);

    return c1+c2-IntesectNum;
}

int main(){

    int n, a,b;
    cin >> n >> a >> b ;

    cout << Divisible(n,a,b);

return 0;
}