#include<iostream>
using namespace std;

// int Fib(int n){
//     if(n==1 || n==0){
//         return 1;

//     }
//     return Fib(n-1) + Fib(n-2);
// }

int Fib( int n){
    int a = 1;
    int b= 0;
    int temp =0;

    for(int i =0 ; i < n; i++){
        temp =a+b;
        a=b;
        b=temp;
    }

    return  a;

}

int main(){

    int n;
    cin >> n;
    

    cout << n << " Number Postion Fib Value is : ";
    cout << Fib(n)<< endl;
  
 

return 0;
}