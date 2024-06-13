// C++ program to demonstrate accessing of data members 
#include <bits/stdc++.h> 
using namespace std; 
class Stu { 
	// Access specifier 
    public: 
	    // Data Members 
	    string stuname; 
	    // Member Functions() 
	    void printname() { cout << "Stuname is:" << stuname; } 
}; 
int main() 
{ 
	// Declare an object of class Stu 
	Stu obj1; 
	// accessing data member 
	obj1.stuname = "SAM"; 
	// accessing member function 
	obj1.printname(); 
	return 0; 
}
