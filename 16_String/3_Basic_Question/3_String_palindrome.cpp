#include<iostream>
using namespace std;

int main(){

    string str;
    cin >> str;
    string original = str;

    int s =0;
    int e = str.size() -1;

    while(s<e){
        swap(str[s],str[e]);
        s++;
        e--;
    }

    cout << str << endl;

    if(original == str){
        cout << "String is palindrome ";
    }else{
        cout << "String is Not palindrome ";
    }

return 0;
}