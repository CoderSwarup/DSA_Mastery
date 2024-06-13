#include <iostream>
using namespace std;

class sum{
	int a;
	int b;
	
	public:
	
	// Creating a Constructor
    // Constructor is a special member function with the same name as of the class.
    //It is used to initialize the objects of its class
    //It is automatically invoked whenever an object is created

	sum(){
		cout << "OBJECT CREATED CONSTRUCTOR CALLED" << endl;
	}
		
};




  	

int main(){
	
  sum s;
   

	
	
	
	return 0;
}
