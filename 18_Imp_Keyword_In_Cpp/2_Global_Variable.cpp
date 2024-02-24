#include<iostream>
using namespace std;


// global variable 
int global = 5; 
  
// global variable accessed from 
// within a function 
void display(){
     //Access the Global Variable in a Function: Inside a function, you can access the global variable using the :: operator.
    // This allows you to differentiate between the local variable and the global variable with the same name. Here’s an example:
    
    cout << "Global global : " << ::global << endl; 

    // Local variable
   
    int global = 232;
    cout << "Local Global : " << global <<  endl << endl;

}

int main(){

    display(); 
  
    // changing value of global 
    // variable from main function 
    global = 10; 
    display(); 

return 0;
}