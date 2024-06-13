#include <iostream>
using namespace std;


class complex{
	int a;
	int b;
	
	public:
	
	complex(int x,int y){
	    a = x;
     	b = y;
	}
	
	complex(){
		a=0;
	    b=0;
	    }
	    
	    
	 complex(int x){
	 	a = x;
	 	b =0;
	 	}
	 	
	void printcom(){
		cout <<"complex number is "<<a<<" + "<<b<<"i "<<endl;
		}
		}; 	
	 	
	 	
	 	
int main(){
	
	complex c1(5);
	c1.printcom();
	
	complex c2(6,8);
	c2.printcom();
	
	complex c3;
	c3.printcom();
	
	
	
return 0;
	}	 	
	    
	    
