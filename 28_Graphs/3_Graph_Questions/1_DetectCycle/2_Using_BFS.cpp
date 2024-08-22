#include<iostream>
using namespace std;
#include <bits/stdc++.h>

// TC O(V+E)
// SC O(V)
bool BFS(int i, vector<int> adj[], vector<bool> &visited) {
    queue<pair<int, int>> q;
    visited[i] = 1;
    q.push(make_pair(i, -1));
    
    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        
        for (int j = 0; j < adj[node].size(); j++) {  // Corrected the loop condition here
            int neighbor = adj[node][j];
            
            if (neighbor == parent) {
                continue;
            }
            
            if (visited[neighbor]) {
                return true;
            }
            
            visited[neighbor] = true;
            q.push(make_pair(neighbor, node));
        }
    }
    
    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    
    for (int i = 0; i < V; i++) {
        if (!visited[i] && BFS(i, adj, visited)) {
            return true;
        }
    }
    
    return false;
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


     cout << endl << "Is Cycle Detect " <<  isCycle(vertex,AdjList);


return 0;
}

