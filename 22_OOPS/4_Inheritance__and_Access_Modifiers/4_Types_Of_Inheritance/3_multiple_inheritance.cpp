//syntax :
// class derived : visibility-mode base1, visibility-mode base2
#include <iostream>
using namespace std;

class Base1{
	protected:
	int b1;
	public:
	void setbase1(){
		b1 = 10;
		}		
};


class Base2{
	protected:
	int b2;
	public:
	void setbase2(){
		b2 = 100;
		}		
};

class derived : public Base1 ,public Base2{
	public:
	void show(){
		cout<<"value of base1 : "<<b1<<endl;	
		cout<<"value of base2 : "<<b2<<endl;
}

};

int main(){
	derived d1;
	d1.setbase1();
	d1.setbase2();
	d1.show();
	
	return 0;
	}
