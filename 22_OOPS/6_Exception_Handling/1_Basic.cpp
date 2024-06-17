#include<iostream>
using namespace std;
#include <bits/stdc++.h>
#include<exception>


class Bank{
    string name;
    int age;
    int amount=0;

    public:
    Bank(string n,int a){
        name=n;
        age=a;
    }

    Deposit(int amount){
        if(amount <=0){
            throw "Invalid Ammount";
        }

        this->amount += amount;
        cout << amount << " Rs Ammount is Deposited" << endl;
    }

     Withdraw(int amount){
        if(amount <=0){
            throw "Invalid Ammount";
        }

        if(this->amount<=0 || this->amount < amount)
        throw "Insufficient Balance";

        this->amount -= amount;
        cout << amount << " RS Ammount is withdraw" << endl;
    }
};



int main(){

    Bank c1("sam",21);

    try{
        c1.Deposit(100);
        c1.Withdraw(2100);
    }catch(const char *s){
        cout << "Exception  : " << s << endl;
    }


return 0;
}