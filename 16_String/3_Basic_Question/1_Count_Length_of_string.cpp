#include<iostream>
using namespace std;

int main(){

    string s;
    cout << "Enter a string : ";
    cin >> s;

    int length =0;
    while(s[length] != '\0'){
        length++;
    }
    cout << "Length of the String is :" << length;

return 0;
}