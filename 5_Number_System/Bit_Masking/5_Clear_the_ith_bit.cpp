
#include<iostream>
using namespace std;

int main(){

   // int n =13 ; // => 1101
    int n = 12 ; // => 1100
    int pos = 3;
    int mask = ~(1<<pos);

    int ans = n&mask;

    cout << ans;


return 0;
}