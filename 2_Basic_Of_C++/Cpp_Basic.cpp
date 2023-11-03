#include <iostream>
using namespace std;
int main()
{
     // Data Types
    int integerVar = 42; // Integer data type
    double doubleVar = 3.14; // Double data type
    char charVar = 'A'; // Character data type
    bool boolVar = true; // Boolean data type

    // Variables and Assignments
    integerVar = 100;
    doubleVar = 2.71828;
    charVar = 'B';
    boolVar = false;

    // Output
    std::cout << "Integer Variable: " << integerVar << std::endl;
    std::cout << "Double Variable: " << doubleVar << std::endl;
    std::cout << "Character Variable: " << charVar << std::endl;
    std::cout << "Boolean Variable: " << boolVar << std::endl;

    // size of all data types 
    cout << "Size of char : " << sizeof(char) << endl;
    cout << "Size of int : " << sizeof(int) << endl;
    cout << "Size of short int : " << sizeof(short int) << endl;
    cout << "Size of long int : " << sizeof(long int) << endl;
    cout << "Size of float : " << sizeof(float) << endl;
    cout << "Size of double : " << sizeof(double) << endl;
    cout << "Size of wchar_t : " << sizeof(wchar_t) << endl;

    // Type Casting
    int castedInt = static_cast<int>(doubleVar); // Casting double to int

    std::cout << "Casted Integer: " << castedInt << std::endl;

    // Operators
    int a = 5;
    int b = 3;
    int sum = a + b; // Addition
    int difference = a - b; // Subtraction
    int product = a * b; // Multiplication
    int quotient = a / b; // Division

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Difference: " << difference << std::endl;
    std::cout << "Product: " << product << std::endl;
    std::cout << "Quotient: " << quotient << std::endl;



 
 return 0;
}
