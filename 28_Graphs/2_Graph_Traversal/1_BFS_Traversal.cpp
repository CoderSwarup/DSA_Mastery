#include<iostream>
using namespace std;
#include <bits/stdc++.h>

// TCO(V+E)
// SC O(V)
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        queue<int> q;
        q.push(0);
        vector<bool> visited(V,0);
        visited[0] =1;
        
        
        
        vector<int> ans;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            ans.push_back(node);
            
            
            for(int j=0;j<adj[node].size();j++){
                if(!visited[adj[node][j]]){
                    visited[adj[node][j]] =1;
                    q.push(adj[node][j]);
                }
            }
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


    for(int i=0;i<vertex;i++){
        cout << i << " -> " ;
        for(int j=0;j<AdjList[i].size();j++){
            cout << AdjList[i][j] << " ";
        }
        cout << endl;
    }


    vector<int> ans = bfsOfGraph(vertex,AdjList);

    cout << endl << "Bfs Traversal Output is " << endl;
    for(int i=0;i<ans.size();i++)
    cout << ans[i] << " ";
return 0;
}



/**
enter the No of Vertex 5

enter the No of Edges 4
0 1
0 2
0 3
2 4
0 -> 1 2 3
1 -> 0
2 -> 0 4
3 -> 0
4 -> 2

Bfs Traversal Output is
0 1 2 3 4


 */