#include<iostream>
using namespace std;
#include <vector>

// Basic Approach 
// Time Complexity => O(n^ 2)
void DivideArrayWithEqualSum(vector<int> arr){
    int n = arr.size();
    bool isDivide = false;
    for(int i=0;i<n-1;i++){
        int sum1 = 0 , sum2 = 0;
        for(int j= 0;j<=i;j++){
            sum1 += arr[j];
        }

         for(int j= i+1;j<n;j++){
            sum2 += arr[j];
        }

        if(sum1 == sum2){
            isDivide = true;
            break;
        }

    }
    if(isDivide){
        cout << "It Can Divide";
    }    else{
        cout << "It Can't Devide";
    }
}


// using Preffix sum approach 
// Time Complexity => O(n)

void DivideArrayUsingPreffix(vector<int> arr){
     int n = arr.size();
    bool isDivide = false;

    int TotalSum = 0;
    for(int i=0;i < n;i++){
        TotalSum += arr[i] ;
    }

    int PreffixSum = 0;
    for(int i =0;i< n-1;i++){
        PreffixSum += arr[i];
        int ans = TotalSum - PreffixSum;
        if(PreffixSum == ans){
            isDivide = true;
            break;
        }

    }
    if(isDivide){
        cout << "It Can Divide";
    }    else{
        cout << "It Can't Devide";
    }
}

int main(){


    vector<int> arr = { 3,4,-2,5,8,200,-10,8};
    // DivideArrayWithEqualSum(arr);
    DivideArrayUsingPreffix(arr);


return 0;
}