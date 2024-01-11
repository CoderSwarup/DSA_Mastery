#include<iostream>
using namespace std;

#include <array>
int main(){

array<int,4> a = {1,2,3,4}; // static Array
cout << a.size();


// cout << *a; 	- Wrong as it will give the first element of array
// cout << &a; - Wrong as it will give address of whole array not individual elements
    for(auto i : a)   // Range based loop to print all elements one by one
    cout << i << " ";
    cout << endl;
    // Accessing Individual Elements using Indexes

    for(int i=0;i<a.size();i++){
        cout << a[i] << endl;
    }

    cout << "Element at index 2 : " << a.at(2);
    cout << "\nArray is empty " << a.empty();

    cout << "\nFirst Index val  " << a.front();
    cout << "\nlast Index val  " << a.back();

    cout << "\nArray max size " << a.max_size();
return 0;
}