#include <iostream>
using namespace std;

// Global variable declaration:
int g = 100;


int main ()
{


 // Local variable declaration:
 int a, b;

 
 // actual initialization
 a = 10;
 b = 20;
 int g = a + b;
 
 
 cout << ::g;
 return 0;
}
 
