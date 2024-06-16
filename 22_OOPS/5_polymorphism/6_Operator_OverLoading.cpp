#include<iostream>
using namespace std;
#include <bits/stdc++.h>

class Complex{
    int i;
    int j;
    public:

    Complex(){}

    Complex(int i,int j){
        this->i=i;
        this->j=j;

    }

    void display(){
        cout<<i<<" + "<<j<<"i"<<endl;
    }


    Complex operator +(Complex &C){
        Complex ans;
        ans.i = i + C.i;
        ans.j = j + C.j;

        return ans;
    }
};

// Which Operator Cannot Overload In cpp?
//1. sizeof
//2. . (Member Access)
//3. .* (Pointer-to-Member Access)
// 4. # (Preprocessor Directives)
//5. ?: (Conditional Operator)
int main(){

    Complex a1(2,4);
    Complex a2(21,41);

    Complex a3 = a1+a2;
    a3.display();
return 0;
}