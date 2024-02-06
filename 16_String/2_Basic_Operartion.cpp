#include<iostream>
using namespace std;


int main(){

    // getline 
    string s;
    getline(cin,s);
    cout << s << endl;

    // Size of the String 
    cout << " Size of the String is : " << s.size() <<endl;

    //  Checking Empty String 
    if (s.empty()) {
        cout << "String is Empty" << endl;
    }else{
        cout << "String is Not Empty" << endl;
    }


    // Concat Two String

    cout << endl << "Concat Two String " <<endl;
    string str1 = "Hello";
    string s3 = s + str1;
    string s4 = s.append(str1);

    cout << s3 << endl;
    cout << s4 <<endl;

    // Add and Remove the Single Charater From the 
    s.push_back('P');

    cout << "Add (P) Character at the last : " << s  << endl; 

    s.pop_back();

    cout << "Remove Last Charater From strign s " << s << endl;



    // Escape charater

    cout << endl << "Escape charater " << endl;

    string ss = "Swarup is a \" Coder \"";
    cout << ss << endl;

    // Null hcarater 
    string Null = "\0";
    cout << Null <<endl;


return 0;
}