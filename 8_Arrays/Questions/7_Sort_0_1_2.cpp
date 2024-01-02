#include<iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

void SortArray(int arr[], int n) {
    int left = 0;
    int right = n - 1;

    while (left < right) {
        while (arr[left] == 0 && left < right) {
            left++;
        }

        while (arr[right] == 1 && left < right) {
            right--;
        }

        if (left < right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}

int main() {
    int n = 7;
    int arr[n] = {0, 1, 0, 0,1, 0, 1};

    SortArray(arr, n);
    printArray(arr, n);

    return 0;
}
