#include<iostream>
using namespace std;
#include <bits/stdc++.h>
#include <fstream>
int main(){

    ifstream fin;
    fin.open("file.txt");

    char c;
    // fin >> c;
    c- fin.get();
    while(!fin.eof()){
        cout << c;
        // fin >> c;
        c= fin.get();
    }


return 0;
}