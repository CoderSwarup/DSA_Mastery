#include<iostream>
using namespace std;

inline int GetMax(int& a,int& b){
    a++;b++;
    return  (a>b)?a:b;
}
int main(){
    int a =0 , b =3;

    cout << GetMax(a,b) << endl; //this is same as (a>b)?a:b;

    cout << a << b;


return 0;
}