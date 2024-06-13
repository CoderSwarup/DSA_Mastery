#include <iostream>
using namespace std;

class sumsub{
	int a,b,c,d;
	public:
	//default constructor
	sumsub(){
		a=30;
		b=20;
		}
		
		//parameterized constructor
		sumsub(int x,int y){
			a=x;
			b=y;
			}
		
	void printsum(){
			cout <<"The sum of "<<a<<" + "<<b<<" is : "<< a+b<<endl;
			}
		
	void printsub(){
			cout <<"The substraction of "<<a<<" - "<<b<<" is : "<< a-b<<endl;
			}	
			
			};				

int main(){
	
	sumsub ss;
	ss.printsub();
	
	sumsub s(20,23);
	s.printsum();
	
	return 0;
	}
	
	
