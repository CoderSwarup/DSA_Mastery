#include<iostream>
using namespace std;
#include <vector>

void printArray(vector<int> &arr){
    for(int i=0;i<arr.size();i++){
        cout<< arr[i] << " ";
    }
                    cout << endl;

}
void selectionSortAcending(vector<int> &arr){
        int size = arr.size();
        for(int i=0;i < size;i++){
            int min_idx = i;

            for(int j=i+1;j<size;j++){
                if(arr[min_idx] > arr[j]){
                    // int temp = arr[min_idx];
                    // arr[min_idx] = arr[j];
                    // arr[j] = temp;
                    
                    swap(arr[min_idx],arr[j]);
                }
            }

        }

        printArray(arr);

}

void selectionSortdecending(vector<int> &arr){
        int size = arr.size();
        for(int i=0;i < size-1;i++){
            int min_idx = i;

            for(int j=i+1;j<size;j++){
                if(arr[min_idx] < arr[j]){
                    swap(arr[min_idx],arr[j]);
                }
            }


        }

        printArray(arr);

}

int main(){

    vector<int> arr  = {3,6,5,21,1};
    cout << "Given array: \n";
    printArray(arr);    
    cout << "\n\nSelection Sort array in acending:\n";
    selectionSortAcending(arr);


    vector<int> arr2  = {20,6,5,21,1};
    cout << "\n\nGiven array: \n";
    printArray(arr2);    
    cout << "\nSelection Sort array in decending:\n";
    selectionSortdecending(arr2);
return 0;
}