#include<iostream>
using namespace std;
#include <vector>


int FindSetBit(int n){
    int count =0;
    while(n!=0){
        if(n&1){
            return count;
        }
        count++;
       n= n>>1;
    }

    return count;
}

int main(){
    vector<int> arr = {5,4,1,4,3,5,1,9};
    int res1 = 0;

    for(auto i :arr){
        res1 = res1 ^i;
    }

   int setbitpos = FindSetBit(res1);

    int a=0 , b=0;

    for(auto i :arr){
        int temp =i>>setbitpos;
        if(temp&1){
             a = a^i;
        }else{
            b = b^i;
        }
    }



    cout << a << " " << b;


return 0;
}