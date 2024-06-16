#include <iostream>
using namespace std;

class base{
	public:
	int a =55;
	// virtual use
   virtual void print(){
	cout<<"the base function is call " <<endl<<
		  "the vale of a is : "<<a<<endl;
		}
		};


class derived: public base{
	public:
	int aa =11;
	void print(){
cout<<"the derived function is call " <<endl<<
		  "the vale of a is : "<<a<<endl<<
		  "value of aa is : "<<aa<<endl;
		}
		};
		
int main(){
      base *b1;
      derived d1;
      b1 = &d1;
      
      b1->print();
      
      return 0;
      }
