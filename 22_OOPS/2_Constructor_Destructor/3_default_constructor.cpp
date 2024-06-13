#include <iostream>
using namespace std;

class sq{
	int a;
	
	public:
	sq();//this is default constructor no parameter decalare 
	
	void printnum(){
		cout <<"The number of "<<a<<" square is : "<<a*a<<endl;
	}
};

		
sq ::sq(){
	a=110;
}
			

int main(){
	
	sq c;
	c.printnum();
	
	return 0;
	}
