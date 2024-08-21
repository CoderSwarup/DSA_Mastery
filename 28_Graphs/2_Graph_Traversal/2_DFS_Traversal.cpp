#include<iostream>
using namespace std;
#include <bits/stdc++.h>


   
// TCO(V+E)
// SC O(V)
void DFS(int node, vector<int> adj[],vector<bool> &visited,vector<int> &ans){
    visited[node] =1;
    
    ans.push_back(node);
    
    
    for(int i=0;i<adj[node].size();i++){
        if(visited[adj[node][i]] == 0){
            DFS(adj[node][i],adj,visited,ans);
        }
    }
}
vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    // Code here
    vector<bool>visited(V,0);
    vector<int>ans;
    
    DFS(0,adj,visited,ans);
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

    vector<int> ans = dfsOfGraph(vertex,AdjList);

    cout << endl << "DFS Traversal Output is " << endl;
    for(int i=0;i<ans.size();i++)
    cout << ans[i] << " ";

return 0;
}



/**

enter the No of Vertex 5

enter the No of Edges 4
0 2
0 3
0 1
2 4
0 -> 2 3 1
1 -> 0
2 -> 0 4
3 -> 0
4 -> 2

DFS Traversal Output is
0 2 4 3 1

 */