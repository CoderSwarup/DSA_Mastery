#include<iostream>
using namespace std;
#include <bits/stdc++.h>



class MainClass{

    public:
    int a, b;

};

class DerivedPublic: public MainClass{
    public:
    void Print(){
        cout << "Derived Public :  "<< endl;
        cout << "A " << a << " B " << b << endl;
    }
};


class DerivedProtected: protected MainClass{
    public:

    void SetValue(int a,int b){
        this->a = a;
        this->b = b;
    }
    void Print(){
        cout << "Derived Protected :  "<< endl;
        cout << "A " << a << " B " << b << endl;
    }
};



class DerivedPrivate: private MainClass{
    public:

    void SetValue(int a,int b){
        this->a = a;
        this->b = b;
    }
    void Print(){
        cout << "Derived Private :  "<< endl;
        cout << "A " << a << " B " << b << endl;
    }
};

int main(){

    DerivedPublic dp1;
    dp1.a =100;
    dp1.b =200;
    dp1.Print();

    //Protected
    DerivedProtected DProtected1;
    //DProtected1.a = 100; //Error
    //DProtected1.b = 200; //Error
    DProtected1.SetValue(100,200);
    DProtected1.Print();


    DerivedPrivate DPrivate1;
    //DPrivate1.a = 100; //Error
    //DPrivate1.b = 200; //Error
    DPrivate1.SetValue(100,200);
    DPrivate1.Print();

return 0;
}