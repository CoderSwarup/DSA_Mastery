#include<iostream>
using namespace std;
#include <bits/stdc++.h>

// TC O(V+E)
// SC O(V)
bool CycleDetect(int node,vector<int> adj[],vector<bool> &visited,vector<bool> &path){

    path[node] =1;
    visited[node] =1;
    
    for(int i=0;i<adj[node].size();i++){

        // check the node is present i the current path
        if(path[adj[node][i]]){
            return 1;
        }

        // If the Neighbourpath is already visited then dont need to go further 
        // help to reduce the TC
        // if(visited[adj[node][i]]){
        //     continue;
        // }
        
        if(!visited[adj[node][i]] && CycleDetect(adj[node][i],adj,visited,path)){
            return 1;
        }
    }
    path[node] =0;
    return 0;
    
}
    // Function to detect cycle in an undirected graph.
bool isCycle(int V, vector<int> adj[]) {
    // Code here
    vector<bool> visited(V,0);
    vector<bool> path(V,0);
    for(int i=0;i<V;i++){
        if(!visited[i] && CycleDetect(i,adj,visited,path))
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
     }


     cout << endl << "Is Cycle Detect Using the  DFS " << isCycle(vertex,AdjList);


return 0;
}

/**
enter the No of Vertex 4

enter the No of Edges 4
0 1
1 2
2 3
3 3

Is Cycle Detect Using the  DFS 1
 */