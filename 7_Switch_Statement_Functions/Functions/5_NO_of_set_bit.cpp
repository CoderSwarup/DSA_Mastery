#include<iostream>
using namespace std;


int bit(int n){
    
  int ans = 0;
  while(n!=0){
    int bit = n&1;
    if(bit==1){
        ans++;
    }
    n = n>>1;
  }

 return ans;
}


int getnum(int a, int b){
    return bit(a) + bit(b);
}

int main(){

  int a = 2;
  int b = 3;

  int ans = getnum(a,b);
  cout << ans;

return 0;
}