#include<iostream>
using namespace std;


int MissingNum(int arr[],int n){
    int sum =0;
    for(int i=0;i<n-1;i++){
        sum += arr[i];
    }

    int ans = n*(n+1)/2;

    return ans-sum;
}

int main(){

    int arr[4] = {1,3,4,5};
    cout << MissingNum(arr,5);

return 0;
}