#include<iostream>
using namespace std;
#include <bits/stdc++.h>

// brute foece
// TC O(N2)
int bestTimeToBuyAndSellStockBrurteForce(vector<int>&prices) {
    // Write your code here.
 
    int MaxProfit = 0;

    for(int i=0;i<prices.size();i++){
       for(int j=i+1;j<prices.size();j++){
        int profit = prices[j] - prices[i];
        MaxProfit= max(profit,MaxProfit);
       }
    }

    return MaxProfit;
}



// OPTIMAL 
// TC O(N)
int bestTimeToBuyAndSellStock(vector<int>&prices) {
    // Write your code here.
    int MinPrice = prices[0];
    int MaxProfit = -1;

    for(int i=0;i<prices.size();i++){
        int profit = prices[i] - MinPrice;
        MaxProfit = max(profit,MaxProfit);
        MinPrice = min(prices[i],MinPrice);
    }

    return MaxProfit;


}
int main(){

       vector<int> arr = {7,1,5,3,6,4};
       cout << bestTimeToBuyAndSellStockBrurteForce(arr);
    //    cout << bestTimeToBuyAndSellStock(arr);


return 0;
}