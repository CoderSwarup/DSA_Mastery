#include<iostream>
using namespace std;
#include <limits.h>
int main(){

    int arr[4][3] = {1,2,3,4,5,6,7,8,9,10,11,12};

    int MaxSum = INT_MIN;
    int MaxSumIndex  = -1;
    for(int i =0;i<4;i++){
        int sum=0;
        for(int j=0;j<3;j++){
            sum+=arr[i][j];
        }
        if(MaxSum<sum){
            MaxSum = sum;
            MaxSumIndex = i;
        }
        
    }
    

    cout << "MaxSum index is " << MaxSumIndex ;

return 0;
}