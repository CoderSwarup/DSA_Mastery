#include <iostream>
using namespace std;

class Bankdepo{
	int principal;
	int years;
	float interestrate;
	int returnvalue;
	
	public:
	//default comstructor
	 Bankdepo(){};
	
	   Bankdepo(int p,int y,float r){//r= value define as 0.18 means (18%)
	   	principal = p;
	   	years = y;
	   	interestrate =r;
	   	returnvalue = principal;
	   	
	   	for(int i = 0;i < y;i++)
	   	{
	   		returnvalue *= (1+interestrate);
	   	}
	   	}
	   	
	   	
	   	
	   	
	    Bankdepo(int p,int y,int r){//r= value define in 18% 
	   	principal = p;
	   	years = y;
	   	interestrate =float(r)/100;//if user enter 18 is convert into 0.18 
	   	returnvalue = principal;
	   	
	   	for(int i = 0;i < y;i++)
	   	{
	   		returnvalue *= (1+interestrate);
	   	}
	   	}
	   	
	   	void showvalue(){
	 cout<<endl<<"Principal amount was "<<principal
        << ". Return value after "<<years
        << " years is "<<returnvalue<<endl;
	   		}
	   	};
	   	
	   	
	

int main(){
	//if not define void constructor than through error here
	Bankdepo b1 ,b2;
	
	int p ,y ;
	float r;
	int R;
	
	cout<<"Enter your principle ammount : ";
	cin >>p;
	cout<<"Enter number of years : ";
	cin >>y;
	cout<<"Enter interestrate(floating_value): ";
	cin >>r;
	
    b1 = Bankdepo(p,y,r);
	b1.showvalue();
	cout<<endl;
	
	
	cout<<"Enter your principle ammount : ";
	cin >>p;
	cout<<"Enter number of years : ";
	cin >>y;
	cout<<"Enter interestrate(int_value): ";
	cin >>R;
	
	b2= Bankdepo(p,y,R);
	b2.showvalue();
	
	
	
	
	return 0;
	}
