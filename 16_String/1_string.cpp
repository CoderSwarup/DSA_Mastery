#include<iostream>
using namespace std;

int main(){

    // using Charater array 
    char arr[] = {'s','w','a','r','u','p'};

    for(int i=0;i<6;i++)
    cout << arr[i] << " ";


    // Input From the use 
    cout << endl;
    char Arr[10];
    cin >> Arr;

    // inserting Null charater
    Arr[2] = '\0';
    cout << Arr;

    cout << "\n String ";
    // Using String
    string str = "swarup";
    cout << endl << str;


    cout << "\nUser Input String Enter a String : ";
    // user Input 
    string str2 ;
    cin >> str2;
    cout << endl << str2;
return 0;
}