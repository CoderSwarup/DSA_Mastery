#include<iostream>
using namespace std;
#include <vector>

void PrintArray(vector<int> array){
    int n = array.size();
    for(int i=0;i < n;i++){
        cout << array[i] << " ";
    }
}

void PrintPriffixSum(vector<int> array){
    int n = array.size();
    int sum =0;

    for(int i = 0;i<n;i++){
        
        array[i] = array[i] + sum;
        sum = array[i];
    }

    PrintArray(array);
}

void PrintSuffixSum(vector<int> array){
    int n = array.size();
    int sum =0;

    for(int i = n-1;i>=0;i--){
        
        array[i] = array[i] + sum;
        sum = array[i];
    }

    PrintArray(array);
}

int main(){

    vector<int> arr = {6,4,5,-3,2,8};
    PrintPriffixSum(arr);
    cout<<endl;
    PrintSuffixSum(arr);


return 0;
}