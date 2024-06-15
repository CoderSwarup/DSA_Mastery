#include<iostream>
using namespace std;
#include <bits/stdc++.h>

class A{

    static int count;
    public:
    // static int count;
    int a= 1;

    A(){
        count++;
    }
    //Onlu access Static Data members 
    static void StaticmemFun(){

        cout<<count<<endl;

        // cout << a;  // error: invalid use of member 'A::a' in static member function        cout << a;
    }
   void display(){
    cout << count << endl;
   }
};

int A::count =1;



int main(){


    A a1,a2,a3,a4,a5;
    a1.display();
  


    // we cant access the Private static data member
    //   A::count =1;
    // a1.display();
    // int c = A::count;
    // cout << "Count of objects: " << c << endl;


    //static Member Function
    A::StaticmemFun();
return 0;
}