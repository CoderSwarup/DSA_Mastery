#include<iostream>
using namespace std;
#include <bits/stdc++.h>

class MyCustomException : public std::exception {
    private:
        char *message;

    public:
        MyCustomException(char *msg) : message(msg) {}
        char *what() {
            return message;
        }
};

int main() {
    try {
        throw MyCustomException("Custom C++ Exception with parameter");
    } catch (MyCustomException mce) {
        std::cout << "Caught MyCustomException" << std::endl;
        std::cout << mce.what();
    }
}