#include <bits/stdc++.h> 
using namespace std;

class Node {
public:
    int index;
    Node *next;
    Node(int x) {
        index = x;
        next = NULL;
    }
};

class NStack {
public:
    int *arr; // integer stack
    Node **top; // node Pointer stack
    stack<int> ES; // Store the empty value of the arr

    // Initialize your data structure.
    NStack(int N, int S) {
        arr = new int[S];
        top = new Node*[N];

        // insert NULL VALUE in the top
        for(int i = 0; i < N; i++) {
            top[i] = NULL;
        }
        for(int i = 0; i < S; i++) {
            ES.push(i);
        }
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m) {
        if(ES.empty()) {
            return false;
        } else {
            int idx = ES.top();
            arr[idx] = x;
            ES.pop();
            
            Node *temp = new Node(idx);
            temp->next = top[m-1];
            top[m-1] = temp;
            return true;
        }
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m) {
        if(top[m-1] == NULL) {
            return -1;
        } else {
            int index = top[m-1]->index;
            int val = arr[index];
            
            Node *temp = top[m-1];
            top[m-1] = top[m-1]->next;
            delete temp;

            ES.push(index);
            return val;
        }
    }

  
};

int main() {
    NStack ns(3, 10);
    ns.push(15, 1);
    ns.push(45, 1);
    cout << ns.pop(1) << endl;
    cout << ns.pop(1) << endl;
    cout << ns.pop(1) << endl;

    return 0;
}
