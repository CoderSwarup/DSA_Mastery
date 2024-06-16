#include <iostream>
using namespace std;

class base{
	public:
	int a;
	// virtual use
	virtual  void print(){
	cout<<"the base function is call " <<endl<<
		  "the vale of a is : "<<a<<endl;
		}
		};


class derived: public base{
	public:
	int a;
	void print(){
cout<<"the derived function is call " <<endl<<
		  "the vale of aa is : "<<a<<endl;
		}
		};
		
int main(){
	base* base_class_pointer;
	base b1;
	derived d1;
	d1.a=22;
	
	base_class_pointer = &d1;
    base_class_pointer->print();
    
   
    derived *d_pointer;
  //  b1.a=666;
  //   d_pointer = &b1;// -> error
  
  
  //you can got garbage value
  //d_pointer->base::a=34;
 // d_pointer->print();
 
 derived d3;
 d_pointer = &d3;
 d3.a=999;
 d_pointer->print();
 
 
	return 0;
	}
