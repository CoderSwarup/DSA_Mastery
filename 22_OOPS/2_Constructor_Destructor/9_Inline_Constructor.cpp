#include<iostream>
using namespace std;
#include <bits/stdc++.h>

class Stu{


    public:
        string sname;
        int roll;

    inline Stu(string name,int r) : sname(name) ,roll(r){

    }

    void Print(){
        cout << "Stu name " << sname << " Roll "<< roll << endl;
    }
};


int main(){


    Stu s1("SAM",3);
    s1.Print();


return 0;
}