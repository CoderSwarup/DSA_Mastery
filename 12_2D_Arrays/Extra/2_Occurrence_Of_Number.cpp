#include<iostream>
using namespace std;
#include <vector>
// using Exptra Space

void Occurrence(vector<int> &arr){
     int n = arr.size();
     vector<int> newarr(n,0);

    // decrease Every value of array by -1
    for(int i=0;i<n;i++){
        newarr[arr[i]-1]++;
    }


    for(int i=0;i<n;i++){
        cout << newarr[i] << " ";
    }
}


void OccurrenceWithoutExtraSpace(vector<int> &arr){
    
    int n = arr.size();

    // decrease Every value of array by -1
    for(int i=0;i<n;i++){
        arr[i]--;
    }

    for(int i=0;i<n;i++){
        int getIndex = arr[i]%n;
        arr[getIndex] = arr[getIndex]+n;
    }

    for(int i=0;i<n;i++){
        int Occurrence = arr[i]/n;
        cout << Occurrence << " ";
    }


}





int main(){

    vector<int> arr = {3,2,5,3,1,2,3,7};


    // Occurrence(arr);
    OccurrenceWithoutExtraSpace(arr);

return 0;
}