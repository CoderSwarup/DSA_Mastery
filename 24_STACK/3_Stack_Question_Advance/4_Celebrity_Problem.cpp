#include<iostream>
using namespace std;
#include <bits/stdc++.h>


 int celebrity(vector<vector<int> >& M, int n) 
{
    // code here 
    stack<int>s;
    for(int i =0;i<n;i++){
        s.push(i);
    }
    
    while(s.size()>1){
        int first = s.top();
        s.pop();
        int sec = s.top();
        s.pop();
        // YES AND NO = P2 CEL
        if(M[first][sec] && !M[sec][first]){
            s.push(sec);
        }
        else if(!M[first][sec] && M[sec][first]){
            // NO AND YES = P1 CEL
            s.push(first);
        }
    }
    
    if(s.empty()) return -1;
    
    int num = s.top();
    int row =0;
    int col =0;
    
    for(int i=0;i<n;i++){
        
        row += M[num][i];
        col += M[i][num];
    }
    
    return row ==0 && col == n-1 ? num : -1;
}

int main(){

    vector<vector<int>> mat =  {{0 1 0},
         {0 0 0}, 
         {0 1 0}};

    cout << "Celebrity is " << celebrity(mat,mat.size());

return 0;
}