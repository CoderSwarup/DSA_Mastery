#include <iostream>
#include <set>

using namespace std;

int main() {
    // Create a set of integers
    set<int> mySet;

    // Insert elements using insert method
    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(30);

    // Display elements using iterator
    cout << "Elements in the set:";
    for (const auto& elem : mySet) {
        cout << " " << elem;
    }
    cout << endl;

    // Check if a value is present in the set
    int valueToFind = 20;
    auto it = mySet.find(valueToFind);
    if (it != mySet.end()) {
        cout << valueToFind << " is found in the set." << endl;
    } else {
        cout << valueToFind << " is not found in the set." << endl;
    }

cout << "count " << mySet.count(2);

    return 0;
}
