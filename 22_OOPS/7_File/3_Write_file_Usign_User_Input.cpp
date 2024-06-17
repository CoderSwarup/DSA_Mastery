#include<iostream>
using namespace std;
#include <bits/stdc++.h>
#include <fstream>
int main(){

    vector<int> arr(5);
    
    for(int i=0;i<5;i++)
    cin >> arr[i];

    ofstream fout;
    fout.open("user.txt");

    for(int i=0;i<5;i++){
        fout<<arr[i];
    }

    fout.close();



return 0;
}