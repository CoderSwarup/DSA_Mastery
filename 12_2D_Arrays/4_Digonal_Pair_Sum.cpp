#include<iostream>
using namespace std;

int main(){

    int arr[4][4] = {5,8,3,9,6,2,8,4,5,3,2,2,2,8,1,9};


    int FirstDiaSum  = 0;
     int SecondDiaSum  = 0;
    for(int i =0;i<4;i++){
        // for(int j=0;j<4;j++){
            FirstDiaSum+=arr[i][i];
            SecondDiaSum+=arr[i][(4-1)-i];
        // }
    }

    cout << FirstDiaSum << " " << SecondDiaSum;

return 0;
}