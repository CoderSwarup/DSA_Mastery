#include<iostream>
using namespace std;
#include <bits/stdc++.h>

class A{
    private:
    int a= 0;
    protected:
    int b = 0;
    public:
    int c =0;

    void SetVal(int a,int b,int c){
        this->a = a;
        this->b = b;
        this->c = c;

    }

    void Print(){
        cout << a << " " << b << " " << c << endl;
    }
};

int main(){

    A a1;
    // a1.a =10;//give error
    // a1.b = 10 ;//give error
    a1.c = 10;

    a1.Print();

    a1.SetVal(20,30,40);
    a1.Print();


return 0;
}