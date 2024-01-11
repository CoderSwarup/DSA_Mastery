#include <iostream>
#include <queue>

using namespace std;

int main() {
    // Create a queue of strings
    queue<string> q;

    // Push elements into the queue
    q.push("a");
    q.push("b");
    q.push("c");

    // Display the front element of the queue
    cout << "Front element: " << q.front() << endl;

    // Pop the front element from the queue
    q.pop();

    // Display the new front element after popping
    cout << "Front element after pop: " << q.front() << endl;

    // Push more elements into the queue
    q.push("d");
    q.push("e");

    // Display all elements in the queue
    cout << "Elements in the queue: ";
    
    // Loop to print all elements in the queue
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();  // Pop each element after printing
    }
    cout << endl;

    return 0;
}
