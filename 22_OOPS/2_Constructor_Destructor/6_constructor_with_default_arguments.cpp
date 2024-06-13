#include <iostream>
using namespace std;

class getdata{
	int data1;
	int data2;
	
	public:
	 getdata(int x ,int y=10){
	 	data1 = x;
	 	data2 = y;
	 	}
	
	 	void printdata();
	 	};

void getdata :: printdata(){
	cout<<"The given Data1 and Data2 value is : "<<data1<<" and " <<data2<<endl;
	}	 		 	 	
	 	

int main(){
	getdata s(2,4);
	s.printdata();//output 2 and 4
	
	cout<<endl;
	
	getdata ss(5);
	ss.printdata();//output 5 and 10 because 10 is default argument
	
	return 0;
	}