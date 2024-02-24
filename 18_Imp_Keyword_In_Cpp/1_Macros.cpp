#include "bits/stdc++.h"
#include<iostream>
using namespace std;

// What are Macros?
// In C++, a macro is part of code that is expanded to its value.
// Macros are defined using the #define directive. 
// They provide a way to create symbolic constants and code snippets that can be reused throughout a program. 
// Macros are processed by the C++ preprocessor, which runs before the actual compilation. During preprocessing,
// macros are replaced with their corresponding values, making it an effective tool for code generation and simplification.


// Syntax 
#define PI 3.14;

// TYPES OF MACROS

// 1. Object-Like Macros
#define VAL 111;


// 2. Function-Like Macros
#define PRINT(x) cout << "Value is: " << x 

//3. Multiline Macros
// Define a macro for printing a rectangle with a given 
// width and height 
#define PRINT_RECTANGLE(width, height)                     \
    for (int i = 0; i < height; i++) {                     \
        for (int j = 0; j < width; j++) {                  \
            std::cout << "*";                              \
        }                                                  \
        std::cout << std::endl;                            \
    } 


// 4. Chain Macros
// defining first macro 
#define CLERK 10 
  
// defining second macro 
#define WORKER CLERK
int main(){

    cout << "MACROS IN CPP" << endl;

    cout << "PI Value : " << PI;
    // PI = 1; //Can't Do this 

    cout << endl << "Types of Macros " << endl;
    cout << "1 . Object-Like Macros : " << VAL;
    cout << endl;

    cout << endl << "2. Function-Like Macros" << endl;
    PRINT(VAL);
    cout << endl;

    cout << endl << "3. Multiline Macros" << endl;
    PRINT_RECTANGLE(4, 3); 

    
    cout << endl << "4. Chain Macros" << endl;
    cout << WORKER << endl;

    cout << endl << "Predefined Macros" << endl << endl;

    cout << "This is line " << __LINE__ << " in file "
         << __FILE__ << "\n"; 
  
    // Display the compilation date 
    cout << "Compiled on " << __DATE__;

return 0;
}