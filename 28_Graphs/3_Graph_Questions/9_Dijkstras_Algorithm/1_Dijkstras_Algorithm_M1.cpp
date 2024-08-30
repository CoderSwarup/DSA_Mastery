#include<iostream>
using namespace std;
#include <bits/stdc++.h>


// TC O(V2)
// SC O(V)
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // Code here
    vector<bool>Explore(V,0);
    vector<int>dist(V,INT_MAX);
    
    dist[S] = 0;
    
   int count = V;
   while(count--){
        int node  =-1, value = INT_MAX;
    
        //Select the node Which is explored yet and its distance value is minimum
        for(int i=0;i<V;i++){
            if(!Explore[i] && value > dist[i]){
                node = i;
                value = dist[i];
            }
        }
        
        Explore[node] =1;
        
        
        for(int j=0;j<adj[node].size();j++){
            int neighbour = adj[node][j][0];
            int weight = adj[node][j][1];
            
            if(!Explore[neighbour] && dist[node]+weight < dist[neighbour]){
                 dist[neighbour] =dist[node]+weight;
            }
        }
   }
   
   return dist;
   
}

int main(){
   int V = 2;
    vector<vector<int>> adj[V] = {{{1, 9}}, {{0, 9}}};
    int S = 0;

    vector<int> ans = dijkstra(V,adj,S);

    for(int i=0;i<ans.size();i++){
            cout << ans[i] << " ";
    }

return 0;
}