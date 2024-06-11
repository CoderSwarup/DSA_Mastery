#include<iostream>
using namespace std;
#include <bits/stdc++.h>
bool isValid(int i,int j,int n){

    return i>=0&&j>=0&&i<n&&j<n;

}

int row[4] = {-1,1,0,0};
int col[4] = {0,0,-1,1};
string dir = "UDLR";

void RatInMaze(vector<vector<int>> &matrix, int i ,int j ,int n,vector<string> &ans,string &path,vector<vector<bool>> &isVisited)
{   

    if(i==n-1&&j==n-1){
        ans.push_back(path);
        return;
    }

    isVisited[i][j] =1;
    // // //up
    if(isValid(i-1,j,n) &&matrix[i-1][j]&&!isVisited[i-1][j]){
        path.push_back('U');
        RatInMaze(matrix,i-1,j,n,ans,path,isVisited);
        path.pop_back();
    }

    //down
      if(isValid(i+1,j,n) &&matrix[i-1][j]&&!isVisited[i+1][j]){
        path.push_back('D');
        RatInMaze(matrix,i+1,j,n,ans,path,isVisited);
        path.pop_back();
    }

    //left 
    if(isValid(i,j-1,n) &&matrix[i][j-1]&&!isVisited[i][j-1]){
        path.push_back('L');
        RatInMaze(matrix,i,j-1,n,ans,path,isVisited);
        path.pop_back();
    }

    //right
    if(isValid(i,j+1,n) &&matrix[i][j+1]&&!isVisited[i][j+1]){
        path.push_back('R');
        RatInMaze(matrix,i,j+1,n,ans,path,isVisited);
        path.pop_back();
    }


    
    //also work

    // for(int k=0;k<4;k++){
    //     if(isValid(i+row[k],j+col[k],n)&&matrix[i+row[k]][j+col[k]]&&!isVisited[i+row[k]][j+col[k]]){

    //         path.push_back(dir[k]);
    //         RatInMaze(matrix,i+row[k],j+col[k],n,ans,path,isVisited);
    //         path.pop_back();
        
    //      }
    // }

   isVisited[i][j] =0;
}


int main(){
    vector<vector<int>> matrix = {{1,0,0,0},{1,1,0,1} ,{1,1,0,0},{0,1,1,1}};
    int n = matrix.size();
    vector<string> ans;
    string path;
    vector<vector<bool>> isVisited(n,vector<bool>(n,0));

    if(matrix[0][0] == 0 || matrix[n-1][n-1] == 0 ){
        cout << "NOT ANS";
        return 0;
    }


    RatInMaze(matrix,0,0,n,ans,path,isVisited);

  for(auto i: ans){
    cout << i << " ";
  }



return 0;
}