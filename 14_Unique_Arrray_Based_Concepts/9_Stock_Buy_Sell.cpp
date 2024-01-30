#include<iostream>
using namespace std;
#include <vector>

// TC +> O(n2)
void StockBuyAndSell(vector<int>stockPrice){
    int n = stockPrice.size();
    int MaxProfit = 0;

    for(int i=0;i < n-1;i++){
        for(int j=i+1;j<n;j++){
                int Profit =  stockPrice[j] - stockPrice[i];
                MaxProfit = max(MaxProfit,Profit);
        }
    }


    cout << MaxProfit;
}

// Tc O(N}
// SC O(N)

// Where We Store The Rightside All Element highest  From Leftside
void StockBuyAndSellWithExtraSpace(vector<int>stockPrice){

    int n = stockPrice.size();
    vector<int> RightMaxValue(n);
    int MaxProfit = 0;
    
    RightMaxValue[n-1] = stockPrice[n-1];

    for(int i =  n-2 ; i >= 0 ; i-- ) {
        int MaxElem = max(stockPrice[i],RightMaxValue[i+1]);
        RightMaxValue[i] = MaxElem;
    }

    for(int i=0;i<n;i++){
       int profit = RightMaxValue[i] - stockPrice[i];
       MaxProfit = max(MaxProfit,profit);
    }


    cout << MaxProfit;

}


// Without Extra Space
// TC => O(N)

void StockBuyAndSellOptimal(vector<int>stockPrice){
    int n = stockPrice.size();
    int MaxProfit =0;
    int closetMinElememt = stockPrice[0];
    for(int i=0;i<n;i++) {
        closetMinElememt = min(closetMinElememt,stockPrice[i]);
        int profit = stockPrice[i] - closetMinElememt;
        MaxProfit =max(profit,MaxProfit);
    
    }

    cout << MaxProfit;
}
int main(){
    vector<int> stockPrice = {3,5,1,7,4,8,3};
    // StockBuyAndSell(stockPrice);
    // StockBuyAndSellWithExtraSpace(stockPrice);
    StockBuyAndSellOptimal(stockPrice);



return 0;
}