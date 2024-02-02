#include<iostream>
using namespace std;

int main(){

    int n = 181; // binary representation: 10110101
    int pos = 3;
    
    // right shift 
    int m1 = n >> pos;
    cout << (m1 & 1) << endl;

    // left shift
    int m2 = 1 << pos;
    cout << ((n & m2) >> pos);

    return 0;
}
