#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Example with std::sort
    vector<int> numbers = {5, 2, 8, 1, 3};
    cout << "Original vector: ";
    for (const auto& num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    sort(numbers.begin(), numbers.end());
    cout << "Sorted vector: ";
    for (const auto& num : numbers) {
        cout << num << " ";
    }
    cout << endl << endl;

    // Example with std::find
    vector<int> values = {10, 20, 30, 40, 50};
    int valueToFind = 30;

    auto it = find(values.begin(), values.end(), valueToFind);
    if (it != values.end()) {
        cout << "Value " << valueToFind << " found in the vector." << endl;
    } else {
        cout << "Value " << valueToFind << " not found in the vector." << endl;
    }
    cout << endl;

    // Example with std::binary_search
    int valueToBinarySearch = 8;
    sort(numbers.begin(), numbers.end());  // Binary search requires a sorted range

    bool isValueFound = binary_search(numbers.begin(), numbers.end(), valueToBinarySearch);
    if (isValueFound) {
        cout << "Value " << valueToBinarySearch << " found in the vector using binary search." << endl;
    } else {
        cout << "Value " << valueToBinarySearch << " not found in the vector using binary search." << endl;
    }
    cout << endl;

    // Example with std::for_each
    vector<int> squares = {1, 2, 3, 4, 5};
    cout << "Original vector: ";
    for (const auto& num : squares) {
        cout << num << " ";
    }
    cout << endl;

    // Use for_each to square each element
    for_each(squares.begin(), squares.end(), [](int& num) {
        num = num * num;
    });

    cout << "Squared vector: ";
    for (const auto& num : squares) {
        cout << num << " ";
    }
    cout << endl;

    // swap 

  int a = 2, b = 3;

    cout << "Before swap: a = " << a << ", b = " << b << endl;

    swap(a, b);

    cout << "After swap: a = " << a << ", b = " << b << endl;


  string aa = "abcd";

    // Use the reverse function to reverse the string
    // reverse(aa.begin(), aa.end());

    cout << aa << endl;

     // Use the rotate function to rotate the string
    rotate(aa.begin(), aa.begin() + 1, aa.end());

    cout << aa << endl;
    return 0;
}
