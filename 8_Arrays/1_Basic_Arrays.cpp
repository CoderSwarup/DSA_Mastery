#include<iostream>
using namespace std;

//array with function 
void ArrayPrint(auto arr[] , int n){
    for (int i =0 ;i <n ; i++){
        cout <<arr[i]<<" ";
    }
}

int main(){

    // Synatax of Array 
    // data_type array_name[size of array] = {value1 , value 2 ,....};

    int arr[3] = {2,3,4};
    cout << sizeof(arr); // 12 because size of the integer is 4 == > 3 * 4 = 12
    cout << endl << arr[2];


    int ar[]  = {6};
    cout << endl << ar[0];

    // Call the printarray Fun
    cout << "Array with Funciton" << endl;
    int Array[10] = {2,3,4,56,67,6};

    
    ArrayPrint( Array, 10);

    // Length of the array 
    int length = sizeof(Array) / sizeof(int); // bad practice becasue this give complete size array if i add the only 2 elements in the 15 size array then its return 15 size

    cout << endl << "Array size is : " << length;

    // Character array 
    cout << endl << "character Array " << endl;
    char ch[4] = {'a','b','c'};
    ArrayPrint(ch,4);
    
    return 0;
}







