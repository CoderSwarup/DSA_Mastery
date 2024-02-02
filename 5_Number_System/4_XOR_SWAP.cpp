#include<iostream>
using namespace std;


// Ex 

// swap 5 and 7 

// a= 5 => 101
//  b= 7 => 111

//  101 = 5
// ^111 = 7
// -----
//  010 == > 2 == a
// ^111
// ----
//  101  ==> 5  == b 

//  010
// ^101
// ----
//  111 ==> 7 == a
int main(){


    int a =5;
    int b =7;

    cout << a << " " << b <<endl;

    a = a ^b;
    b = a^ b;
    a =a^b;

    cout << a << " " << b;



return 0;
}