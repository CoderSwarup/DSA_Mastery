#include<iostream>
using namespace std;


int main(){

    int n;
    cin>>n;

    int m =n;
    int mask = 0;
    if(m==0){
        return 1;
    }
    while(m!=0){
        mask = (mask<<1)|1; //  0000.....0000 | 1 << 00000....0001 << 00000..0010 | 1 << 00000....0110 | 1 ..........

        m = m>>1;// 0000000101 >> 0000000...10 >> 00000.....01 >> 000000....0
    }

    int ans = (~n) & mask;  //  ~n ==> 1111111010  ==>  1111111010 & 0000000111 ==> 00000000010


    cout<<ans<< ~0;

return 0;
}