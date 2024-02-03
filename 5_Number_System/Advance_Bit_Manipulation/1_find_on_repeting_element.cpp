#include<iostream>
using namespace std;

int main(){

    int arr[7] = {5,4,1,4,3,5,1};

    int res =0;
    
    for(int i=0;i<7;i++){
        res = res^arr[i];
        cout << res << " "; 
    }



return 0;
}