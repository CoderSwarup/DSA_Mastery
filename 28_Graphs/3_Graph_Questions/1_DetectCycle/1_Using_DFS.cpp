#include<iostream>
using namespace std;
#include <bits/stdc++.h>

// TC O(V+E)
// SC O(V)
bool CycleDetect(int node,int parent,vector<int> adj[],vector<bool> &visited){
    
    visited[node] =1;
    
    for(int i=0;i<adj[node].size();i++){
        if(parent == adj[node][i]){
            continue;
        }
        if(visited[adj[node][i]]){
            return 1;
        }
        
        if(CycleDetect(adj[node][i],node,adj,visited)){
            return 1;
        }
    }
    
    return 0;
    
}
    // Function to detect cycle in an undirected graph.
bool isCycle(int V, vector<int> adj[]) {
    // Code here
    vector<bool> visited(V,0);
    for(int i=0;i<V;i++){
        if(!visited[i] && CycleDetect(i,-1,adj,visited))
        return 1;
    }
    
    return 0;
         
}

int main(){
     int vertex , edges;
    cout << "enter the No of Vertex " ;
    cin >> vertex;
    cout << endl << "enter the No of Edges " ;
    cin >> edges;


    vector<int> AdjList[vertex];

    int u ,v;
    for(int i=0;i<edges;i++){
        cin >> u >> v ;
        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
     }


     cout << endl << "Is Cycle Detect " << isCycle(vertex,AdjList);


return 0;
}

/**
enter the No of Vertex 5

enter the No of Edges 5
0 1
1 2
1 4
2 3
3 4

Is Cycle Detect 1

 */