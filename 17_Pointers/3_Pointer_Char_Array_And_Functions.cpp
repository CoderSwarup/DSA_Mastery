#include<iostream>
using namespace std;
#include <vector>

void swapping(int *n1, int *n2){
    int temp = *n1;
     *n1 = *n2;
    *n2 =temp;
}

void swappingPassByRef(int &n1,int &n2){
    int temp = n1;
    n1 =n2;
    n2 = temp;
}

void passingVectorValues(vector<int> &v){
    for(int i=0;i<v.size();i++){
        v[i]  = 111;
    }
}


void ArrayusingPointer(int *p){
    for(int i=0;i<4;i++){
        p[i] = p[i]*2;
    }
}

int main(){
    cout << endl << "+++++++++++++++Pointer With Charater Array+++++++++++++++++++ " << endl;  
    // Character array pointer
    char arr[5] = "1234";
    char *ptr = arr;

    
    cout<< "Try to print the Address of the char arr using arr : "<< arr <<endl;
    cout << "Try to print the Address of the char arr using ptr : " << ptr << endl;

    cout << endl;

    cout << "Try to print the Address of the char arr using void pointer (void*)arr : " << (void*)arr << endl;

    // how to access the charater array element
    cout << "arr 0th index element  using *ptr : " << *ptr << endl;


    cout << endl ;

    char a = 'a';

    cout << "Address of the charater a using &a: " << &a << endl;
    cout << "Address of the charater a using ( void*)&a: " << ( void*)&a << endl;
    cout << "Address of the charater a using static_cast<void*>(&a) : " << static_cast<void*>(&a) << endl;


    cout << endl << "+++++++++++++++Pointer With Functions+++++++++++++++++++ " << endl;
    //swapping two numbers
    int n1 = 10;
    int n2 = 20;
    cout << "Before Swap n1 and n2 : " << n1 << " and " << n2 << endl;
    swapping(&n1,&n2);
    cout << "After Swap n1 and n2 : " << n1 << " and " << n2 << endl;

    cout << endl << "+++ Pass By refrence ++ " << endl;
    cout << "Before Swap n1 and n2 : " << n1 << " and " << n2 << endl;
    swappingPassByRef(n1,n2);
    cout << "After Swap n1 and n2 : " << n1 << " and " << n2 << endl;

    cout << endl << "+++++ Pass by refrence with vector +++ "<< endl;
    vector<int>v(5,0);
    cout << "Before pasing Vector values : " ;
    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    cout << endl <<  "After pasing Vector values : ";
    passingVectorValues(v);
    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }


    cout << endl << "+++++ array with pointer +++ "<< endl;
    int array[4]={1,3,4,6};
    cout << "Before pasing array values : " ;
    for(int i=0;i<4;i++){
        cout << array[i] << " ";
    }
    ArrayusingPointer(array);
    cout << endl <<  "After pasing array values : ";
    for(int i=0;i<4;i++){
        cout << array[i] << " ";
    }


return 0;
}