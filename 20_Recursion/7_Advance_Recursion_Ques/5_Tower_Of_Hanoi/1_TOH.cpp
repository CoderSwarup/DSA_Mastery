#include<iostream>
using namespace std;
#include <bits/stdc++.h>


//TC 2n -1

// ex 
// n=3 => step 7
// n=4 => step 15

//SC O(N)
void TOH(int n , int S,int H,int D,int &i){
    if(n==1){
        i++;
        cout << "Disk " << n << " from " << S << " TO " << D << endl;
        return;
    }


    //Move n-1 disk source To Helper
    TOH(n-1,S,D,H,i);
    i++;
    cout << "Disk " << n << " from " << S << " TO " << D << endl;

    // Move disk n-1 from Helper To Destination
    TOH(n-1,H,S,D,i);
}

int main(){
    int i=0;
    TOH(5,1,2,3,i);
    cout << i;


return 0;
}