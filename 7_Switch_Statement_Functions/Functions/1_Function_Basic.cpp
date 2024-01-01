// function
  //Syntax
          //    returntype functionName(Parameters){

                   // function body
        //   }

#include <iostream>
using namespace std;

void display(); // Function prototype

    int main(){
      
       int a;
       cout << "1}  Initializing display function"<<endl;
        
       display();  //Function call

        cout << "3} display function finished its work"<<endl;

    return 0;
}

// Function Defination
void display(){

    cout << "2} This is Display function"<<endl;
};
