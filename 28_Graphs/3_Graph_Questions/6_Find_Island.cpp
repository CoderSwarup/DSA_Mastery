#include<iostream>
using namespace std;
#include <bits/stdc++.h>
// TC O(m*n)
// SC O(m*n)
int row[8] = {-1,-1,-1,  1,1,1,  0,0};
int col[8] = {-1,0,1,   -1,0,1, -1,1};

int r;
int c;

bool valid(int i,int j){
    return (i >= 0 && i < r && j >= 0 && j < c);
}
// Function to find the number of islands.
int numIslands(vector<vector<char>>& grid) {
    // Code here
    
    r = grid.size();
    c = grid[0].size();
    
    queue<pair<int,int>> q;
    
    int count =0;
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            
            if(grid[i][j] == '1'){
                count++;
                
                
                q.push(make_pair(i,j));
                grid[i][j] = '0';
                
                
                while(!q.empty()){
                    int new_i = q.front().first;
                    int new_j = q.front().second;
                    
                    q.pop();
                    
                    //check the new connected island
                    for(int k=0;k<8;k++){
                        int ni = new_i + row[k];
                        int nj = new_j + col[k];
                        
                        if(valid(ni,nj) && grid[ni][nj] == '1'){
                            grid[ni][nj] = '0';
                            q.push(make_pair(ni,nj));
                        }
                    }
                }
            }
        }
    }
    
    return count;
}

int main(){

    int r = 5, c = 4;
    vector<vector<char>> grid = {
        {'1', '0', '1', '1'},
        {'0', '1', '0', '1'},
        {'1', '1', '0', '1'},
        {'0', '0', '1', '1'},
        {'1', '1', '1', '1'}
    };

    int result = numIslands(grid);
    cout << "Number of islands: " << result << endl;

return 0;
}