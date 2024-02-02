#include<iostream>
using namespace std;

int main(){

       // int n =13 ; // => 1101
    int n = 12 ; // => 1100
    int pos = 1;
    int mask = n>>pos;

    int ans = mask&1;

    cout << ans;


return 0;
}