#include<iostream>
using namespace std;

int main(){

    int n;
    cin>>n;

    int i=0;
    int ans =0;
    int mul =1;

    while(n!=0){
        int rem = n%8;
         ans = (mul*rem)+ans;
        cout<<(mul*rem)<<endl;
        mul*=10; 
        n/=8;
    }

    cout<<ans;
return 0;
}