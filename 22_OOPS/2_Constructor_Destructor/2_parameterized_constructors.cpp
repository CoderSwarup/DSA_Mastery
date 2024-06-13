#include <iostream>
using namespace std;

class sum{
	
	int a ,b;
	
	public:
	sum(int ,int );//declaration of parameterized constructor
	
	void printnum(){
	cout<<"The number of "<<a <<" + "<<b <<" is = " <<a+b<<endl;
		}
	
	};
	
	
sum :: sum(int x,int y){
	a = x;
	b = y;
	}
		
	

int main(){
	//implicit call
	sum a(33,44);
	
	a.printnum();
	
	//explicit call
	sum b = sum(2,3);
	b.printnum();
	
	return 0;
	}
