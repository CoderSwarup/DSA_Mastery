#include<iostream>
#include<math.h>
using namespace std;

int main(){

    int n ;
    cin>>number;
    // 16
    int ans =1;
    for(int i=0;i<=30;i++){
        // int power = pow(2,i);
        if(ans==n){
            return true;
        }else{
            return false;
        }
        ans = ans*2;
    }


return 0;
}