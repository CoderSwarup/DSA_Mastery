#include<iostream>
using namespace std;

int main(){
    // int n =13 ; // => 1101
    int n = 12 ; // => 1100
    int pos = 1;
    int mask = 1<< pos;

    int ans = n&mask;

    if(ans ==0){
        cout << "No";
    }else{
        cout << "Yes";
    }

return 0;
}