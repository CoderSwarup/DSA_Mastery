#include<iostream>
using namespace std;
#include <bits/stdc++.h>

// TC
// => ((V-1) * E + E)
// => WC V*E
// => BC E


//SC O(V)
vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
    // Code here
    
    
    vector<int> dist(V,1e8);
    // 1e8 10 POW 8
    
    dist[S] = 0;
    
    int e = edges.size();
    
    
    // Relax the edges V-1
    for(int i=0;i<V-1;i++){
        
        bool flag  =0;
        
        
        for(int j=0;j<e;j++){
            int u= edges[j][0];
            int v = edges[j][1];
            int weight = edges[j][2];
            
            
            // handle the edge case (1e8+ weight < 1e8 )
            if(dist[u] == 1e8){
                continue;
            }
            
            //relax edge
            if(dist[u]+weight < dist[v]){
                flag = 1;
                dist[v] = dist[u]+weight;
            }
        }
        
        
        // if distance not change 
        if(!flag){
            return dist;
        }
    }

    //Relax One more time to detect the cycle
    for(int j=0;j<e;j++){
            int u= edges[j][0];
            int v = edges[j][1];
            int weight = edges[j][2];
            
            
             // handle the edge case (1e8+ weight < 1e8 )
            if(dist[u] == 1e8){
                continue;
            }
            
            
            //relax edge
            if(dist[u]+weight < dist[v]){
                //Cycle Detected
                vector<int> ans;
                ans.push_back(-1);
                return ans;
            }
    }
    
    
    return dist;
    
}
int main(){

    int V = 2;
    int S = 0;
    vector<vector<int>>edges = {{0,1,9}};
    vector<int> ans = bellman_ford(V,edges,S);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

return 0;
}