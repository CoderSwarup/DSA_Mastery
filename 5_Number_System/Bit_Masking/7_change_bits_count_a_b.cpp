#include<iostream>
using namespace std;

void countBit(int n){
        int count = 0;

    while(n!=0){
        if(n&1){
            count++;
        }
       n= n>>1;
    }
    cout <<count;
}


// using n&(n-1) 

void countBit2(int n){
        int count = 0;

    while(n!=0){
        n = n&(n-1);
        count++;
        
       
    }
    cout <<count;
}

int main(){
    int a = 14; // 1110
    int b = 13; //1101

    int ans = a&b;
    countBit(ans);
    countBit2(ans);


return 0;
}