#include<iostream>
using namespace std;
#include <vector>
// int arr2[10000000] ={0};
int main(){

    vector<int> arr = {1,3,2,1,3};
    // int arr2[1000000000] ={0}; // throw error
    vector<int> Hash(arr.size()+1,0);

    // insertion in hashing
    for (int i=0;i<arr.size();i++){
        Hash[arr[i]] += 1;
    }

    // Fetch the Number How Many Times Appear
    int q;
    cin >> q;
    while(q--){
        int x;
        cin >> x;
        cout << x <<  "Appears : " << Hash[x] << endl;
    }




return 0;
}