#include<iostream>
using namespace std;
#include <bits/stdc++.h>

// Brute force 
int floorSqrtBF(int n) {
    int ans = 0;
    //linear search on the answer space:
    for (long long i = 1; i <= n; i++) {
        long long val = i * i;
        if (val <= n * 1ll) {
            ans = i;
        } else {
            break;
        }
    }
    return ans;
}




 long long int floorSqrt(long long int x) 
    {
        // Your code goes here   
        long long int low =0;
        long long int high = x;


        cout <<  low <<" " << high << endl;
        long long int p =0;
        if(x%2 !=0){
            p = 1;
        }
        
        while(low <= high){
            long long int mid = low +((high-low)/2);
            long long int ans = (mid*mid) +p;
            cout << ans << " " << mid << endl;
            if(ans == x){
                return mid;
            }else if(ans > x){
                high = mid -1;
            }else{
                low = mid +1;
            }
           
        }
        
        return -1;
    }

// Optimal 
int floorSqrtOptimal(int n) {
    int low = 1, high = n;
    //Binary search on the answers:
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long val = mid * mid;
        if (val <= (long long)(n)) {
            //eliminate the left half:
            low = mid + 1;
        }
        else {
            //eliminate the right half:
            high = mid - 1;
        }
    }
    return high;
}

int main(){
    int x = 5;
    // cout << floorSqrtBF(x) << endl;
    cout << floorSqrtOptimal(x) << endl;

    // long long int x = 5;
    // cout << floorSqrt(x);


return 0;
}