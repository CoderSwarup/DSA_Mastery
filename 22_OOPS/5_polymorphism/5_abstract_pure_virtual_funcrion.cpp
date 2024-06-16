//abstract base class its make for create a drived class from base class 
//pure virtual function use to every derived class make its onw functuon 

#include <iostream>
#include <string>
using namespace std;

class student{
	protected:
	string name;
	int roll_no;
	public:
	
     student(string s , int r){
     	name  = s;
     	roll_no = r;
     	}
     
    virtual void display()=0; //do nothing somthing --> pure virtual function
    
    };
   
class coding : public student{
	float code_rating;
	public:
	
	coding(string s , int r , float c): student(s,r){
		code_rating = c;
		}
	 
	void display(){
  cout<<"Dear student : "<<name<<" welcome "<<endl<<
		"Your Roll_no is : "<<roll_no<<endl<<
		"Your coding rating is "<<code_rating<<endl;
		}
};


class marks : public student{
	float mark;
	public:
	
	marks(string s , int r, float m): student(s,r){
		mark = m;
		}
	 
	void display(){
  cout<<"Dear student : "<<name<<" welcome "<<endl<<
		"Your Roll_no is : "<<roll_no<<endl<<
		"Your marks : "<<mark<<endl;
		}
};

int main(){
	string name;
	int roll_no;
	float code_rating ;
	float mark;
	
	name  = "sam";
	roll_no=333;
	code_rating=4.66;
	coding code(name,roll_no,code_rating);
	code.display();
	
	cout<<endl;
	
	
	name = "sammy";
	roll_no = 222;
	mark = 450;
	marks mark2(name,roll_no,mark);
	mark2.display();
	
	
	cout<<endl;
	//using pointer
	student *arr[2];
	arr[0]=&code;
	arr[1]=&mark2;
	arr[1]->display();
	return 0;
	}
