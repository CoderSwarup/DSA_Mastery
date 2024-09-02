#include<iostream>
using namespace std;
#include <bits/stdc++.h>
// TC O(n3)
void shortest_distance(vector<vector<int>>&matrix){
    // Code here
    
    int n = matrix.size();
    
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            
            if(matrix[i][j] == -1){
                matrix[i][j] = INT_MAX;
            }
        }
        
    }
    
    
   // Flyod Warshall 
   for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
           
                if(matrix[i][k] == INT_MAX || matrix[k][j] == INT_MAX)
                continue;
           
           
                matrix[i][j] = min(matrix[i][j] , matrix[i][k]+matrix[k][j]);
            
            }
        
        }
   }
   
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            
            if(matrix[i][j] == INT_MAX){
                matrix[i][j] = -1;
            }
        }
        
    }
   
}

int main(){

    vector<vector<int>>matrix = {{0,25},{-1,0}};

    shortest_distance(matrix);
    cout << "Aftet Applying the Floyd Warshall " <<endl;

    int n = matrix.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            
            cout << matrix[i][j] << " ";
        }
        cout << endl;
        
    }



return 0;
}