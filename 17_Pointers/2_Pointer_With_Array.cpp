#include<iostream>
using namespace std;

int main(){

    
    int arr[5] = {1,2,4,5,6};

    // print the Address of the array 0th index
    cout << "Address of arr 0th index (arr) : " << arr <<endl;
    cout << "Address of arr 0th index  (arr+0) : " << (arr+0) <<endl;
    cout << "Address of arr 0th index  (&arr[0]) : " << (&arr[0]) <<endl;
    int *ptr = arr;
    cout << "Address of arr 0th index using pointer  varialble ptr : " << ptr <<endl;
    cout << "Address of arr 0th index  (&(*arr)) : " << (&(*arr)) <<endl;


    // pritn   the address of the 1th index 
    cout << "Address of arr 1st index (arr+1) : " << (arr+1) <<endl;
    cout << "Address of arr 1st index (&arr[1]): " << (&arr[1]) <<endl;


    //print the value of the index 0
    cout << "Value of arr index 0  arr[0]:  " << arr[0] << endl;
    cout << "Value of arr index 0  (*arr) : " << (*arr) << endl;
    cout << "Value of arr index 0  (*arr+0) : " << (*arr+0) << endl;


    //print the All address of the Array
    for(int i=0;i<5;i++){
        cout << "address of " << i << "index : " << arr+i <<endl;
    }

     for(int i=0;i<5;i++){
        cout << "value of " << i << "index : " << *(arr+i) <<endl;
    }

    cout << endl << "Print all the values and Adress of array using The Pointer Variable " << endl;


    // print all the address 
    for(int i=0;i<5;i++){ 
        cout << "address of " << i << " index  using ptr+i : " << ptr+i <<endl;
    }

    // print all the value of the array using poiter Variable
    for(int i=0;i<5;i++){
        cout << "value of " << i << "index using ptr[i] : " << ptr[i] <<endl;
    }


    // Arithmatic Operation in array using Ponter 
    cout << "Arithmatic Operation (++ , -- ) on the Array Using Pointer : "<<endl;

    for(int i=0;i<5;i++){
        cout << *ptr << endl;
        ptr++;
    }

    cout << endl;

    //Addition
    ptr = arr;
    ptr = ptr + 2;
    cout << *ptr;

    // Bad Practice 
    // arr++; // Nor allowed 


    



return 0;
}