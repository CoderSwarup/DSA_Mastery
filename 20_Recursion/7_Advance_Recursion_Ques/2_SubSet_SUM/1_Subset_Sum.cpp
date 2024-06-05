#include<iostream>
using namespace std;
#include <bits/stdc++.h>

// void subSetSum(vector<int> &arr,int i,int n, vector<vector<int>> &ans, vector<int> &temp){
//        if(i == n){
//         int sum = 0;
//         for(int j=0;j<temp.size();j++)
//         sum+= temp[j];
//         ans.push_back({sum});
//         return;
//     }
//     subSetSum(arr,i+1,n,ans,temp);
//     temp.push_back(arr[i]);
//     subSetSum(arr,i+1,n,ans,temp);
//     temp.pop_back();

// }


// Subset Sum 
void subSetSumM2(vector<int> &arr,int i,int n, int sum){
    if(i == n){
       cout << sum << " ";
       return ;
    }
    subSetSumM2(arr,i+1,n,sum);

     subSetSumM2(arr,i+1,n,sum+arr[i]);
}



// subset sum with the 
void subsetSumM3(vector<int> arr , int i,int n, vector<vector<vector<int>>> &ans, int sum,vector<int> &temp){
    if(i==n){
        ans.push_back({{sum},temp});
        return;
    }

    // not include 
    subsetSumM3(arr,i+1,n,ans,sum,temp);

    // include
    temp.push_back(arr[i]);
    subsetSumM3(arr,i+1,n,ans,sum+arr[i],temp);
    temp.pop_back();
}
int main(){
    // METHOD 1
    // vector<int> arr = {1,2,3};
    // vector<vector<int>> ans;
    // vector<int> temp;

    // // subSetSum(arr,0,arr.size(),ans,temp);

    // for(int i=0;i<ans.size();i++){
    //     for(int j=0;j<ans[i].size();j++){
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << endl;

    // }

    // METHOD 2
    //  vector<int> arr = {1,2,3};

    // subSetSumM2(arr,0,arr.size(),0);
    


    // METHOD 3
    vector<int> arr = {1,2,3};
    vector<vector<vector<int>>> ans;
    vector<int> temp;
    subsetSumM3(arr,0,arr.size(),ans,0,temp);
    for (const auto& matrix : ans) {
        cout << "{\n";
        for (const auto& row : matrix) {
            cout << "  { ";
            for (int value : row) {
                cout << value << " ";
            }
            cout << "}\n";
        }
        cout << "}\n";
    }
    for(int i=0;i<ans.size();i++){
    bool firstTime = true;
         for(int j=0;j<ans[i].size();j++){
            for(int k=0;k<ans[i][j].size();k++){
                cout << ans[i][j][k] << " ";
             }
            if (firstTime) {
                std::cout << " => ";
            }
            firstTime = false;
         }
        cout << endl;
    }

return 0;
}