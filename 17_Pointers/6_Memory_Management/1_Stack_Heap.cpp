#include<iostream>
using namespace std;

int main(){

    // Stack Memeory Allocation to Variable  in C++ (Static)
    int n = 10;
    cout << "Static Memory Allocation : " << n << endl;

    // Heap Memory Allocation  to Variable in C++ (Dynamic)
    int *ptr = new int;
    *ptr = 129;
    cout << "Dynamic Memory Allocation : " << *ptr << endl;

    // Dunamic Memory Allocation to Array 

    int num;
    cout << endl<<"Enter the Size of the Array : " ;
    cin >> num;
    int *p = new int[n];


    // Value  Assignment for Dynamic Memory Allocated Array
    for(int i=0;i < num;i++)
    p[i] = i+1;


    for(int i=0;i < num;i++)
    cout << p[i] << endl;



    //Relase The heap Memory Using delete Keyword 

    delete ptr;
    delete p;

return 0;
}