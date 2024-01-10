
#include <bits/stdc++.h>
using namespace std;

void insertionSort(int n, vector<int> &arr){
    for(int i=1;i<n;i++){
        int temp = arr[i];

        int j = i-1;
        for(;j>=0;j--){

            if(arr[j] >temp ){
                arr[j+1] = arr[j];
            }else{
                break;
            }
        }
        arr[j+1] = temp;

    }
}

int main(){
    // Create an array
    vector<int> arr = {12, 11, 13, 5, 6};

    cout << "Original array: ";
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }

    // Apply insertion sort
    insertionSort(arr.size(), arr);

    cout << "\nSorted array (Insertion Sort): ";
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }

    return 0;
}
