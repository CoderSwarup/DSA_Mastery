#include<iostream>
using namespace std;
#include <map>


int main(){
    int n;
    cin >>n;
    int arr[n];

    // map
    map<int,int>Map;


    for(int i =0;i<n;i++){
        cin >> arr[i];
        Map[arr[i]]++;

    }

    // iterate Map
    for(auto i:Map){
        cout << i.first << " -> " << i.second << endl;
    }

    int q;
    cin >> q;
    while(q--){
        int x;
        cin >> x;
        cout << x <<  "Appears : " << Map[x] << endl;
    }




return 0;
}