#include <iostream>
#include <vector>
using namespace std;

void reverseArray(vector<int> &arr, int m) {
    int s = m+1;
    int e = arr.size() - 1;

    while (s < e) {
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}

void printarray(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};

    int m = 3; // specify the starting position
    reverseArray(arr, m);
    printarray(arr);

    return 0;
}
