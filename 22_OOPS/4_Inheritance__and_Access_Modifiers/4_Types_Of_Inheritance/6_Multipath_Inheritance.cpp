#include <iostream> 
using namespace std; 
class A { 
public: 
    void say() 
    { 
        cout << "Hello world"<<endl; 
    } 
}; 
class B : public virtual A { 
};   
class C : public virtual  A {//if not use virtual through error
};   
class D : public B, public C { 
}; 


int main(){
	D d;
	d.say();
	
	
 return 0;
 }
