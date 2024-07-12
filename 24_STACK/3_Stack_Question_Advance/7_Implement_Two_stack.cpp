#include <iostream>
using namespace std;

class twoStacks {
public:
    int *arr;
    int top1;
    int top2;
    int size;

    // Constructor to initialize the two stacks in a single array.
    twoStacks(int n = 100) {
        size = n;
        arr = new int[n];
        top1 = -1; // Initial position of top for stack1
        top2 = n;  // Initial position of top for stack2
    }

    // Function to push an integer into the stack1.
    void push1(int x) {
        // There should be space between top1 and top2
        if (top1 < top2 - 1) {
            top1++;
            arr[top1] = x;
        } else {
            cout << "Stack1 Overflow" << endl;
        }
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        // There should be space between top1 and top2
        if (top2 > top1 + 1) {
            top2--;
            arr[top2] = x;
        } else {
            cout << "Stack2 Overflow" << endl;
        }
    }

    // Function to remove an element from top of the stack1.
    int pop1() {
        if (top1 >= 0) {
            int x = arr[top1];
            top1--;
            return x;
        } else {
            cout << "Stack1 Underflow" << endl;
            return -1; // Stack1 is empty
        }
    }

    // Function to remove an element from top of the stack2.
    int pop2() {
        if (top2 < size) {
            int x = arr[top2];
            top2++;
            return x;
        } else {
            cout << "Stack2 Underflow" << endl;
            return -1; // Stack2 is empty
        }
    }
};

int main() {
    twoStacks ts(10);

    // Push elements into stack1
    ts.push1(5);
    ts.push1(10);
    ts.push1(15);

    // Push elements into stack2
    ts.push2(20);
    ts.push2(25);
    ts.push2(30);

    // Pop elements from stack1
    cout << "Popped from stack1: " << ts.pop1() << endl; // Should print 15
    cout << "Popped from stack1: " << ts.pop1() << endl; // Should print 10

    // Pop elements from stack2
    cout << "Popped from stack2: " << ts.pop2() << endl; // Should print 30
    cout << "Popped from stack2: " << ts.pop2() << endl; // Should print 25

    // Push more elements into stack1
    ts.push1(40);
    ts.push1(50);

    // Push more elements into stack2
    ts.push2(60);
    ts.push2(70);

    // Pop remaining elements from stack1
    cout << "Popped from stack1: " << ts.pop1() << endl; // Should print 50
    cout << "Popped from stack1: " << ts.pop1() << endl; // Should print 40
    cout << "Popped from stack1: " << ts.pop1() << endl; // Should print 5
    cout << "Popped from stack1: " << ts.pop1() << endl; // Should print -1 (Underflow)

    // Pop remaining elements from stack2
    cout << "Popped from stack2: " << ts.pop2() << endl; // Should print 70
    cout << "Popped from stack2: " << ts.pop2() << endl; // Should print 60
    cout << "Popped from stack2: " << ts.pop2() << endl; // Should print 20
    cout << "Popped from stack2: " << ts.pop2() << endl; // Should print -1 (Underflow)

    return 0;
}
