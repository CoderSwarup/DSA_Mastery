#include<iostream>
using namespace std;

int main(){

    int n = 8;
    int mask = n&(n-1);

if((mask&0) ==0 ){
    cout<<"yes";
}else{
    cout<<"NO";
}

return 0;
}