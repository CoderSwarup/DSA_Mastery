#include <iostream>
using namespace std;


// Global variable declaration:
int g = 20;

int main ()
{
 // Local variable declaration:
 int g = 10;

 cout <<"Local opretor value is " << g<< endl;

 //get the value of globle variable use ==> (::g)
 cout <<"globle operator value is using :: " << ::g << endl;
 return 0;
}
