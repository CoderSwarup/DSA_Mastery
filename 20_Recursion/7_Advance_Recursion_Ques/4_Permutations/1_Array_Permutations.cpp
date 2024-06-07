#include<iostream>
using namespace std;
#include <bits/stdc++.h>

void ArrayPermutation(vector<int> &arr,vector<vector<int>> &ans,vector<int> &temp,vector<bool> &visited){
    if(arr.size() == temp.size()){

        ans.push_back(temp);
        return;

    }

    for(int i=0;i<arr.size();i++){
        if(visited[i] == 0){
            visited[i] =1;
            temp.push_back(arr[i]);
            ArrayPermutation(arr,ans,temp,visited);
            visited[i] =0;
            temp.pop_back();
        }
    }

}

void ArrayPermutationWithoutExtraArray(vector<int> &arr,vector<vector<int>> &ans,int index){
    if(arr.size() == index){

        ans.push_back(arr);
        return;

    }

    for(int i=index;i<arr.size();i++){
        swap(arr[i],arr[index]);
        ArrayPermutationWithoutExtraArray(arr,ans,index+1);
        swap(arr[i],arr[index]);
    }

}

int main(){

    vector<int> arr = {1,2,3};
    vector<vector<int>> ans;
    vector<int> temp;
    vector<bool> visited(arr.size(),0);


    // ArrayPermutation(arr,ans,temp,visited);
    ArrayPermutationWithoutExtraArray(arr,ans,0);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
return 0;
}