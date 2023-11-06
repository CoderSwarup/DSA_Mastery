#include<iostream>
using namespace std;

int main(){

    int a = 5;
    int b = 3;

    cout << "a&b : " << (a&b) <<endl;
    cout << "a|b : " << (a|b) <<endl;
    cout << "~a : " << (~a) <<endl;
    cout << "a^b : " << (a^b) <<endl;
    cout << "a<<2 : " << (a<<2) <<endl; // 58 2 = 10 * 2 = 20
    cout << "a<< : " << (a<<1) <<endl; 
    cout << "b>>1 : " << (b>>1) <<endl;

    // Increment And Decrement Operator 

    cout << endl << "Pre Increment and Decrment  "<< endl;
    // Post Increment 
    cout << "Before a++ is : "<< a++ << endl;
    cout << "After a++ is : "<< a << endl;

        // Post Decrement  
    cout << "Before a-- is : "<< a-- << endl;
    cout << "After a-- is : "<< a << endl;

     cout << endl << "Pre Increment and Decrement  "<< endl;
        // Pre Increment 
    cout << "Before ++a is : "<< ++a << endl;
    cout << "After ++a is : "<< a << endl;

        // Pre Decrement  
    cout << "Before --a is : "<< --a << endl;
    cout << "After a-- is : "<< a << endl;


    // Sample Question 
    int i = 1;
    cout << (i++) << endl;
    cout << (i--) << endl;
    cout << (--i) << endl;
    cout << (++i) << endl;

    cout <<i;



return 0;
}