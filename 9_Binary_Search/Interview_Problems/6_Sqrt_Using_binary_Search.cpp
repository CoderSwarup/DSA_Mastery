#include<iostream>
//https://leetcode.com/problems/sqrtx/
using namespace std;
    int BinarySearch(int n){
       
         if (n == 0 || n == 1)
            return n;
        long long int ans = 0;
     

        int s = 0;
        int e = n-1;
        long long int mid = s+(e-s)/2;

        while(s<=e){
            long long int square = mid * mid;

            if(square == n){
                return mid;
            }
            if(square < n){
                ans = mid;
                s = mid +1;
            }
            if (square > n){
            e = mid-1;
            }


            mid = s+(e-s)/2;

        }
    return ans;
    }


    double morePrecision(int n, int precision, int tempSol) {
    
    double factor = 1;
    double ans = tempSol;

    for(int i=0; i<precision; i++) {
        factor = factor/10;

        for(double j=ans; j*j<n; j= j+factor ){
            ans = j;
        }
    }
    return ans;
}
int main(){

int n;
cout << "Enter a Interger  : " ;
cin >> n;
int ans = BinarySearch(n);
// cout << ans;
 cout <<" Answer is " << morePrecision(n, 3, ans) << endl;



return 0;
}