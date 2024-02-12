#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>


void print_Factorial(int n){
     vector<int>ans(1,1);

    while(n>1){
        int carry =0;
        int res =0;
        int size = ans.size();

        for(int i=0;i<size;i++){
            res = ans[i]*n+carry;
            carry = res/10;
            ans[i] = res%10;
        }

        while(carry){
            ans.push_back(carry%10);
            carry /=10;
        }

        n--;
    }


    reverse(ans.begin(),ans.end());


    for(auto i:ans){
        cout << i;
    }
}



int main(){
    int n;
    cout << "Enter a Number : ";
    cin >> n;

    print_Factorial(n);
   




return 0;
}