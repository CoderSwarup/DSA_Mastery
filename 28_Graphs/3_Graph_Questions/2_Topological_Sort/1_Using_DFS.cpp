#include<iostream>
using namespace std;
#include <bits/stdc++.h>

// TC O(V+E)
// SC O(V)
void DFS(int node,vector<int>adj[],vector<bool> &visited,stack<int> &s){
    visited[node] =1;
    
    //look it neighbour 
    for(int i=0;i<adj[node].size();i++){
        if(!visited[adj[node][i]]){
            DFS(adj[node][i],adj,visited,s);
        }
    }
    
    s.push(node);
}
vector<int> topoSort(int V, vector<int> adj[]) 
{
    // code here
    vector<bool> visited(V,0);
    stack<int>s;
    
    for(int i=0;i<V;i++){
        if(!visited[i]){
            DFS(i,adj,visited,s);
        }
    }
    
    vector<int>ans;
    
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    
    
    return ans;
    
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


     cout << endl << "Topo sort Using DFS" << endl ;
     vector<int> ans = topoSort(vertex,AdjList);

     for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
     }


return 0;
}

/**
enter the No of Vertex 4

enter the No of Edges 3
1 0
2 0
3 0

Topo sort 
0 3 2 1 

 */