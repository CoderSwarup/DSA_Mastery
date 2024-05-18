#include<iostream>
using namespace std;
#include <bits/stdc++.h>

// brute force 

// TC (O(M*N))
int mul(int i, int n){
	    int s = 1;
	    for(int j = 1;j<=n;j++){
	        s *= i;
	    }
	    
	    return s;
}
int NthRootBruteForce(int n, int m)
{
	    // Code here.
	    
	for(int i=1;i<m;i++){
	    if(mul(i,n) == m){
	        return i;
	    }
        else if(mul(i,n) > m){
            break;
        }
	}
	    
	return -1;
}  


// Binary search 

// if ans < m return 0;
// if ans == m return 1;
// if ans > m return 2;
int mul(int i, int n,int m){
    long long s = 1; 
    for (int j = 1; j <= n; j++) {
        s *= i;
        if (s > m) return 2;
    }
    if (s == m) return 1;
return 0;
}
int NthRoot(int n, int m)
{
    // Code here.
    int low = 1;
    int high = m;	
   
   while(low <= high ){
       int mid = low +((high-low)/2);
       int ans = mul(mid,n,m);
       if(ans == 1){
           return mid;
       }else if(ans == 2){
           high = mid -1;
       }else{
           low = mid +1;
       }
   }
    
    return -1;
}  

int main(){
    int n = 3, m = 27;
    // int ans = NthRootBruteForce(n, m);
    int ans = NthRoot(n, m);
    cout << "The answer is: " << ans << "\n";
    return 0;


return 0;
}