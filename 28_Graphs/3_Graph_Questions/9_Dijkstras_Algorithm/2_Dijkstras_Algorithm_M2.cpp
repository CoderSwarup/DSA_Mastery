#include<iostream>
using namespace std;
#include <bits/stdc++.h>


// USing the Priority Queue
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // Code here
    vector<bool>Explore(V,0);
    vector<int>dist(V,INT_MAX);
    
    dist[S] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> >
    pq;
    pq.push({0,S});
    
    

   while(!pq.empty()){
       int node = pq.top().second;
       pq.pop();
       
       if(Explore[node]){
           continue;
       }

        
        //Relax the Edges 
        for(int j=0;j<adj[node].size();j++){
            int neighbour = adj[node][j][0];
            int weight = adj[node][j][1];
            
            if(!Explore[neighbour] && dist[node]+weight < dist[neighbour]){
                 dist[neighbour] =dist[node]+weight;
                 pq.push({dist[neighbour],neighbour});
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