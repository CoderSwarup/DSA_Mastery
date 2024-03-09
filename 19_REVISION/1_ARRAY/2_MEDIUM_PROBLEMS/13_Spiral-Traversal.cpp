#include<iostream>
using namespace std;
#include <bits/stdc++.h>

vector<int> printSpiral( vector<vector<int>>& mat){
    int n = mat.size();
    int m = mat[0].size();

    // initialize top left bottom and right 
    // row        // column
    int top = 0 , left =0;
    int bottom = n-1 , right = m-1;


    vector<int> ans;


    // run the while loop still the left <= right && top <= bottom
    while(top <= bottom && left <= right){

        // first the loop go left to right 
        // here top is constant 
        for(int i=left;i<=right;i++){
            ans.push_back(mat[top][i]);
        }
        top++;


        // now tranver the loop from top to bottom 
        // where the right is constant 
        for(int i= top;i<=bottom;i++){
            ans.push_back(mat[i][right]);
        }
        right--;

        // now the loop traverse from the right to left 
        // here is the bottom is constant 
        // but here edge case also that is 
        //         => if the top exceed the bottom 

        if(top <= bottom){
            for(int i=right;i>= left;i--){
                ans.push_back(mat[bottom][i]);
            }
        bottom--;
        }


        // now the trave the bottom to top 
        // here is left is constant 
        // and also here the edage case is that  
        //          => if the left is less than right 

        if(left <= right){
            for(int i=bottom;i>=top;i--){
                 ans.push_back(mat[i][left]);
            }
        left++;
        }


    }
    return ans;
}


int main(){

    vector<vector<int>> mat   {{1, 2, 3, 4},
                             {5, 6, 7, 8},
	                         {9, 10, 11, 12},
		                     {13, 14, 15, 16}};
		                     
  vector<int> ans = printSpiral(mat);

  for(int i = 0;i<ans.size();i++){
      
      cout<<ans[i]<<" ";
  }
  

return 0;
}