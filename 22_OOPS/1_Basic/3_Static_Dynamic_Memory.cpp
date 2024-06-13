#include<iostream>
using namespace std;
#include <bits/stdc++.h>


class Stu{

    public:
        string name;


        void printname(){
            cout << "STUDENT NAME : " << name;
        }
};

int main(){

    Stu *s = new Stu;
    (*s).name = "SAM";

    s->printname();



return 0;
}