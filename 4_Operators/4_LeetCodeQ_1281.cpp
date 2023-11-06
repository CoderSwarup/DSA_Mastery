#include<iostream>
using namespace std;

// Q 1281. Subtract the Product and Sum of Digits of an Integer

// Example 1:

// Input: n = 234
// Output: 15 
// Explanation: 
// Product of digits = 2 * 3 * 4 = 24 
// Sum of digits = 2 + 3 + 4 = 9 
// Result = 24 - 9 = 15

int main(){

    int n = 234;
     int product = 1;
     int sum = 0;

     while(n!=0){
        int rem = n % 10;
        product *= rem;
        sum += rem;
        n /= 10;
     }

     int ans = product - sum ;
     cout<<ans<<endl;


return 0;
}