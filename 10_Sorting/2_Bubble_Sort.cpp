#include<iostream>
#include <vector>
using namespace std;

// Function to print the elements of a vector
void printArray(vector<int> &arr){
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Bubble sort without optimization for vectors
void bubbleSort1(vector<int>& arr, int n)
{   
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - 1; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    // Print sorted vector
    cout << "Sorted array (Bubble Sort): ";
    printArray(arr); 
}

// Optimized bubble sort for vectors
void bubbleSortOptimize(vector<int>& arr, int n)
{   
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    // Print sorted vector
    cout << "Sorted array (Optimized Bubble Sort): ";
    printArray(arr); 
}

// An optimized version of Bubble Sort for arrays
void bubbleSortMorOptimized(vector<int>& arr, int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
 
        // If no two elements were swapped
        // by inner loop, then break
        if (swapped == false)
            break;
    }

    printArray(arr);
}

int main(){
    // First vector
    vector<int> arr1 = {3, 6, 5, 21, 1};
    cout << "Given array: ";
    printArray(arr1);    
    cout << "\nBubble Sort array in ascending order:\n";
    bubbleSort1(arr1, arr1.size());

    // Second vector
    vector<int> arr2 = {20, 6, 5, 21, 1};
    cout << "\nGiven array: ";
    printArray(arr2);    
    cout << "\nBubble Sort array in optimized way:\n";
    bubbleSortOptimize(arr2, arr2.size());

    // Third array
    vector<int> arr3 = {10, 8, 7, 5, 2};
    cout << "\nGiven array: ";
    printArray(arr3);    
    cout << "\nBubble Sort array in more optimized way (for arrays):\n";
    bubbleSortMorOptimized(arr3, arr3.size());

    return 0;
}
