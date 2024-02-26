#include<iostream>
using namespace std;
#include <vector>
int isSorted(int n, vector<int> a) {
    // Write your code here.

    for(int i=1;i<n;i++){
        if(a[i-1] > a[i]){
            return 0;
        }
    }

    return 1;
}

int main(){
    vector<int> arr = {1, 2, 35, 4, 5};
    cout << "Is sorted Array : " << isSorted(arr.size(), arr);


return 0;
}