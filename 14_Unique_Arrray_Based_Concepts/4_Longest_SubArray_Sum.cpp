#include<iostream>
using namespace std;
#include <vector>
#include <limits.h>
// Basic Approach 
// Time Complexity = > O(n^3)
void LogestSum(vector<int> array){
    int n = array.size();
    int MaxSum = INT_MIN;

    // By we want to loop iterate From the 1 to n-1 
    for(int size = 1 ;size <= n;size++){
        
        // this loop want to run from  < n- size  + 1 || <=  n- size
        for(int i =0;i<=n-size;i++){
            int PreffixSum = 0;

            
            //here we print that every subarray 
            // so we want to start the loop from  i 
            // end the loop with i+size
            for(int j =i; j<i+size;j++){
            PreffixSum += array[j];
            }
            // cout << PreffixSum << " "<< MaxSum << endl;
            MaxSum = max(MaxSum,PreffixSum);
            

        }
       
    }

    cout << MaxSum;
}



// Using Preffix Method
// Time Complexity => O(n^2)

void LogestSumPreffix(vector<int> array){
    int n = array.size();
    int MaxSum = INT_MIN;

    for(int i = 0; i<n;i++){

        int PreffixSum = 0;
        for(int j = i;j<n;j++){
            PreffixSum += array[j];
            MaxSum = max(PreffixSum,MaxSum);
        }

    }

    cout << MaxSum ;
}




// using Kadanes Algorithm 
// here Create a PriffixSum is Negative Then they Convert Into The 0
// Time complexity => O(n)
void KadanesAlgo(vector<int> array){
    int n = array.size();
    int MaxSum = INT_MIN;
    int PreffixSum = 0;
    for(int i = 0; i<n;i++){
        PreffixSum += array[i];
        MaxSum = max(PreffixSum,MaxSum);
        if(PreffixSum<0){
            PreffixSum = 0;
        }
    }

    cout << MaxSum ;

}
int main(){

    vector<int> arr = {6,4,-12,5};
    // LogestSum(arr);
    // LogestSumPreffix(arr);
    // KadanesAlgo(arr);

return 0;
}

