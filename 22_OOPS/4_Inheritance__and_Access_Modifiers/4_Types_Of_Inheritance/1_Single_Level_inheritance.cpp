#include<iostream>
using namespace std;
#include <bits/stdc++.h>


class Human{
    protected:
    string name;
    int age;


    public:

    Human(){};

    Human(string name,int age){
        this->name = name;
        this->age = age;
    }

};

class Student : public Human{

    protected:
    int rollNo;
    string course;

    public:
    Student(string name,int age, int rollNo,string course):Human(name,age){
        // this->name = name;
        // this->age = age;
        this-> rollNo = rollNo;
        this->course = course;
    }


    void Display(){
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "Course: " << course << endl;

    }
};

int main(){
    Student s1("sam",20,5,"BSC");
    s1.Display();



return 0;
}