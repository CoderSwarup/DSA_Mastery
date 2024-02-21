#include<iostream>
using namespace std;


void Change( int **p){
    *p = *p +1;
}

void ChangePassByRef(int &p){
    // &p++;// Not Possible
    cout << endl << "pointer *p Addres Using Pass By Ref &p : " << &p << endl;
}

int main(){

    // Double & multiple pointer 
    // Every Pointer Contains the Address of (pointer(n) -1)Memeory Location 

    int n = 10;
    int *p = &n;
    cout << "Single pointer *p Address : " << p << endl;
    int **p1 = &p;
    cout << "Double pointer **p1 Address : " << p1 << endl;
    int ***p2 = &p1;
    cout << "Triple pointer ***p2 Address : " << p2 << endl;

    cout << endl << "Check the Address Of ***p2 and &p1 : " << endl;
    cout << p2 << endl;
    cout << &p1 << endl << endl;


    cout << "Value n Modification Using Pointers"<< endl;
    cout << "Value of n  : " << n << endl;
    *p = *p +1;
    cout << "Value of n After *p = *p +1  : " << n << endl;
    **p1 = **p1 +10;
    cout << "Value of n After **p1 = **p1 +10  : " << n << endl;
    ***p2 = ***p2 +10;
    cout << "Value of n After ***p2 = ***p2 +10  : " << n << endl;



    // Address Changing Using Pointer
    cout << endl;

    cout << "*p Address is : " << p <<endl;
    // Change(p);// Not Possible 
     Change(p1); 
    cout << "*p Address is : " << p <<endl;
    ChangePassByRef(*p);
    cout << "*p Address is : " << p <<endl;
    

return 0;
}