#include<iostream>
using namespace std;
#include <vector>

void countPrimes(int n){
    int count = 0;
    if(n<1){
        cout << count;
        return;
    }
    for(int i=2;i<n;i++){
        bool isPrime = true;
        for(int j =2;j<i;j++){
            if(i%j == 0){
                isPrime = false;
            }
        }

        if(isPrime)
            count++;
        

    }

    cout << count;
}

// using Sieve of Eratosthenes Algorithm 

// where we First Mark all the elemets are prime 
// Then Cehck The Elemetn is Prime or not
// if its Prime Then all the Values of that table Set as Non Prime

void SieveofEratosthenes(int n){
    vector<bool> primes(n+1,true);
    int count = 0;
    primes[0] = primes[1] == false;

    for(int i =2;i<n;i++){
        if(primes[i]){
            count++;

            // Prime table all values Set As The Non Prime 
            for(int j=2*i;j<n;j+=i){
                primes[j] = false;
            }
        }
    }
    cout << count;
}

int main(){

    int n = 10;
    // countPrimes(n);
    SieveofEratosthenes(n);


return 0;
}