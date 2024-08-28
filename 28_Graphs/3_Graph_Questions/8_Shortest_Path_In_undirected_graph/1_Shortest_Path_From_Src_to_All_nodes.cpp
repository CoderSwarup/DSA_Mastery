#include<iostream>
using namespace std;
#include <bits/stdc++.h>




 vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
    // code here
    vector<int> adj[N];
    
    for(int i=0;i<M;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    
    //Distance
    vector<int> dist(N,-1);
    vector<bool> visited(N,0);
    
    queue<int> q;
    q.push(src);
    dist[src] =0;
    visited[src] =1;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(int j=0;j<adj[node].size();j++){
            if(visited[adj[node][j]]){
                continue;
            }
            
            visited[adj[node][j]] =1;
            q.push(adj[node][j]);
            dist[adj[node][j]] = dist[node]+1;
        }
    }
    
    return dist;
}

int main(){
vector<vector<int>> edges = {{0,1},{0,3},{3,4},{4,5},{5,6},{1,2},{2,6},{6,7},{7,8},{6,8}};
int N = 10;int M = 10;
 int src = 0;

 vector<int> ans  = shortestPath(edges,N,M,src);

    cout << "Distance from the Source " << src << " To All nodes is " << endl;

 for(int i=0;i<ans.size() ;i++){
    cout << src << " -> " << i << " :: " << ans[i] << endl;
 }

return 0;
}