#include<iostream>
using namespace std;

int main(){

    //Syntax Of the Pointer
    //=> data_typ *pointer_Variable_name = &variable_name;

    int a = 10;
    int b = 20;
    cout << "Address of a : " << &a << endl;
    cout << "Address of b : " << &b << endl;


    // Access the Address of the Variable a In pointer
    int *ptr = &a;
    cout << "Address of a using *ptr : " << ptr <<endl;


      // print the Address and Value using pointer varable
    cout << "Address of Pointer : ptr : " << ptr <<endl;
    cout << "Value of the Pointer :  *ptr : " << *ptr << endl;

    // Size of the Pointer
    cout << "Size of the Pointer : " << sizeof(ptr) << endl;


    cout << endl << endl;

    cout << "value of a before  (*ptr)++  : " << a <<endl;
    (*ptr)++;
    cout << "value of a after  (*ptr)++  : " << a <<endl;




    cout << endl << endl;









    // Character Pointer 

    char c = 'a';
    char *charPointer = &c;
    cout << "Size of the Character Pointer  : " << sizeof(charPointer) << endl;

    cout << endl << "Bad Practice of the Pointer" << endl;

    // int *p; // Not define like this 
    // int *p = 0;  // also this give the null  pointer give segmentation fault

    // cout << *p << endl;


    cout << endl << "Copy pointer " << endl;

    int aa = 10;

    int *p1 = &aa;
    int *p2 = p1; 

    cout << "Address of *p1 " << p1 <<endl;
    cout << "Address of *p2 " << p2 <<endl;
    cout << "Value of *p1 " << *p1 <<endl;
    cout << "Value of *p2 " << *p2 <<endl;
  

    cout << "Pointer Address Increment " <<endl;
    int d =10;
    int *pp = &b;

    cout << "Address of * pp  Before pp = pp + 1 : " << pp << endl; //0x61fef0
    pp += 1;
    cout << "Address of * pp  After pp = pp + 1 : " << pp << endl; //0x61fef4

 



return 0;
}