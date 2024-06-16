#include <iostream>
using namespace std;
//multilevel inheritance 

class student{
	protected:
	int roll_num;
	public:
	
	void set_rollnum(int n){
		roll_num = n ;
		}
	void get_rollnum(){
		cout<<"Your roll number is : "<<roll_num<<endl;
		}
	};
	
//inherite student class
class exam : public student{
	protected:
	float a , b , c , d , e;
	public:
	void setmarks(float x, float y , float z,float xx ,float yy){
		a=x;
		b=y;
		c=z;
		d=xx;
		e=yy;
		}
	
	void getmarks(){
		cout<<"your enter marks total is :"<<a+b+c+d+e<<endl;
		}
		
	};

//inherite exam class
class result : public exam{
	protected:
	float percentage;
	public:
	void display(){
		get_rollnum();
		getmarks();
		cout<<"Your percentage is : "<< ((a+b+c+d+e)/5)<<"% congragulation.."<<endl;
		}
		};
	


int main(){
	result sam;
	int n;
	cout<<"Enter your roll number : "<<endl;
	cin>>n;
	sam.set_rollnum(n);
	
	float a , b, c ,d,e;
	cout<<"Enter your python marks : "<<endl;
	cin>>a;
	cout<<"Enter your linux marks : "<<endl;
	cin>>b;
	cout<<"Enter your cod marks : "<<endl;
	cin>>c;
	cout<<"Enter your discrete mathamatics marks : "<<endl;
	cin>>d;
	cout<<"Enter your open source  marks : "<<endl;
	cin>>e;
	
	cout <<endl;
	
	sam.setmarks(a,b,c,d,e);
	sam.display();
	
	
	return 0;
	}
