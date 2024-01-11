#include<iostream>
#include<list>

using namespace std;

int main() {
    // Create a linked list using STL list
    list<int> l;

    // Insert elements at the back and front of the list
    l.push_back(1);
    l.push_front(2);

    // Display the elements using a range-based for loop
    cout << "Elements in the list:" << endl;
    for (auto i : l) {
        cout << i << endl;
    }

    // Display the size of the list
    cout << "Size of List: " << l.size() << endl;

    // Copy the list to another list (l2)
    list<int> l2(l);

    // Display elements of the copied list
    cout << "Elements in the copied list (l2):" << endl;
    for (auto e : l2) {
        cout << e << endl;
    }

    // Insert more elements to the original list
    l.push_back(3);
    l.push_front(4);

    // Display the updated elements in the original list
    cout << "Updated elements in the original list:" << endl;
    for (auto i : l) {
        cout << i << endl;
    }

    return 0;
}
