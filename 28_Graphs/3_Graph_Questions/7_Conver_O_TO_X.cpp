#include<iostream>
using namespace std;
#include <bits/stdc++.h>

int row[4] = {-1,1,0,0};
int col[4] = {0,0,-1,1};

int r;
int c;

bool valid(int i,int j){
    return (i >= 0 && i < r && j >= 0 && j < c);
}

vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
{
    // code here
    r = n;
    c = m;
    
    // boundary Traversal 
    
    queue<pair<int,int>> q;
    
    // first row
    for(int j=0;j<c;j++){
        if(mat[0][j] == 'O'){
            q.push(make_pair(0,j));
            mat[0][j] = '#';
        }
    }
    //first col
    for(int i=1;i<r;i++){
        if(mat[i][0] == 'O'){
            q.push(make_pair(i,0));
            mat[i][0] = '#';
        }
    }
    
    //last row 
    for(int j=1;j<c;j++){
        if(mat[r-1][j] == 'O'){
            q.push(make_pair(r-1,j));
            mat[r-1][j] = '#';
        }
    }
    // last col
    for(int i=1;i<r-1;i++){
        if(mat[i][c-1] == 'O'){
            q.push(make_pair(i,c-1));
            mat[i][c-1] = '#';
        }
    }
    
    
    // while q 
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        
        q.pop();
        
        for(int k=0;k<4;k++){
            if(valid(i+row[k],j + col[k]) && mat[i+row[k]][j + col[k]] == 'O'){
                    mat[i+row[k]][j + col[k]] = '#';
                    q.push(make_pair(i+row[k],j + col[k]));
            }
        }
    }
    
    //ramin all o to x and replace all # to x
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(mat[i][j] == 'O'){
                mat[i][j] = 'X';
            }
            if(mat[i][j] == '#'){
                mat[i][j] = 'O';
            }
        }
    }
    
    
    return mat;
}

int main(){

    int n = 5, m = 4;
    vector<vector<char>>mat = {{'X', 'X', 'X', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'O', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}};

    vector<vector<char>> ans = fill(n,m,mat);

    cout << "After Conversion " << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

return 0;
}