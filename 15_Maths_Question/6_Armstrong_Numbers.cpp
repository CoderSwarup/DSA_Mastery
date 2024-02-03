#include <iostream>
using namespace std;

void isArmstrongNumbers(int n){
    int sum = 0, temp = n;
    while(n > 0){
        int digit = n % 10;
        sum = sum + (digit * digit * digit); // Use multiplication instead of pow
        n /= 10;
    }

    cout << temp << " " << sum << " ";
    if(temp == sum){
        cout << "yes";
    } else {
        cout << "no";
    }
}

int main(){
    int n = 153;
    isArmstrongNumbers(n);

    return 0;
}
