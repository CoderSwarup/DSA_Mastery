#include<iostream>
#include<stack>

using namespace std;

int main() {
    // Create a stack of integers
    stack<int> s;

    // Push elements into the stack
    s.push(1);
    s.push(2);
    s.push(32);

    // Display the top element of the stack
    cout << s.top() << endl;

    // Pop the top element from the stack
    s.pop();

    // Display the new top element after popping
    cout << endl << s.top() << endl;

    // Push another element into the stack
    s.push(322);

    // Display the size of the stack
    cout << s.size() << endl;

    return 0;
}
