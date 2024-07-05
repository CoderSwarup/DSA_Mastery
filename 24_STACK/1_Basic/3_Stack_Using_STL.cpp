#include<iostream>
using namespace std;
#include <stack>
int main(){

    stack<int>s;

    // push the stack
    s.push(1);
    s.push(22);

    // pop the elem from the stack
    // s.pop();


    // peak element from the stack
    cout << s.top() << endl;

    // size of the stack
    cout << s.size() << endl;

    // is stack empty
    cout << s.empty() << endl;



return 0;
}