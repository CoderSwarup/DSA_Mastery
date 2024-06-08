#include<iostream>
using namespace std;
#include <bits/stdc++.h>


void PermutationWithRepeate(vector<int> &arr, set<vector<int>> &ans, vector<int> &temp, vector<int> &isVisited){

        if(arr.size() == temp.size()){

            ans.insert(temp);
            return; 
        }

        for(int i=0;i<arr.size();i++){
            if(isVisited[i] ==0){
                isVisited[i] = 1;
                temp.push_back(arr[i]);
                PermutationWithRepeate(arr,ans,temp,isVisited);
                isVisited[i] =0;
                 temp.pop_back();
            }
        }
}


void PermutationWithRepeateM2(vector<int> &arr,vector<vector<int>> &ans,int index){
    if(index == arr.size()){
        ans.push_back(arr);
        return;
    }

    vector<int> checker(21,0);
    for(int i=index;i<arr.size();i++){
        bool isAlreadySwap = checker[arr[i] +10];
        if(isAlreadySwap == 0){
            swap(arr[i],arr[index]);
            PermutationWithRepeateM2(arr,ans,index+1);
            swap(arr[i],arr[index]);
            checker[arr[i] +10] = 1;
        }
    }

}

int main(){


    vector<int> arr = {1,1,2};
    set<vector<int>> ans;
    vector<int> temp;
    vector<int> isVisited(arr.size(),0);
    // PermutationWithRepeate(arr,ans,temp,isVisited);
 
    // for (auto it = ans.begin(); it != ans.end(); ++it) {
    //     // Traverse each vector
    //     for (int val : *it) {
    //         cout << val << " ";
    //     }
    //     cout << endl; // New line for each vector
    //  }


     //Mehtod 2
    vector<vector<int>> ans2;

    PermutationWithRepeateM2(arr,ans2,0);
      for(int i=0;i<ans2.size();i++){
        for(int j=0;j<ans2[i].size();j++){
            cout << ans2[i][j] << " ";
        }
        cout << endl;
    }


return 0;
}