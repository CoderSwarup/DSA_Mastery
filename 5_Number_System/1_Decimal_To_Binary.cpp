#include<iostream>
#include<math.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    int answer = 0;
    int i =0;

    // Method 1 
    // while(n!=0){
    //     int rem = n%2;

    //     cout << rem;
    //     answer = (rem * pow(10,i))  + answer;
    //     n /= 2; // if n = 5 == > 5/2 => 2 /2 => 1 /2 => 0
    //     i++;
       
    // }
    // cout<<endl<<"Answer is : " <<answer;

     //Method 2
    //   while (n != 0) {
    //     int bit = n & 1;
    //     answer = (bit * pow(10,i)) + answer;
    //     n = n >> 1;
    //     i++;
    // }
    //  cout<<endl<<"Answer is : " <<answer;


    // Using Array 
    // int array[32];

    // while(n!=0){
    //     int rem = n%2;
    //     array[i] = rem;
    //     n/=2;
    //     i++;


    // }
    
    // for (int j = i - 1; j >= 0; j--) {
    //     cout << array[j]; 
    // }

    int mul =1;
    int ans = 0;
    while(n!=0){
        int rem = n%2;
        ans = (mul*rem)+ans;
        mul*=10; 
        n/=2;
    }

    cout<<ans;
return 0;
}