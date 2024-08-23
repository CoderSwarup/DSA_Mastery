
/**
Kahn’s Algorithm for Topological Sorting:
Kahn’s Algorithm for Topological Sorting is a method used to order the vertices of a directed graph in a linear order such that for every directed edge from vertex A to vertex B, A comes before B in the order. The algorithm works by repeatedly finding vertices with no incoming edges, removing them from the graph, and updating the incoming edges of the remaining vertices. This process continues until all vertices have been ordered.
 */
#include<iostream>
using namespace std;
#include <bits/stdc++.h>

// TC O(V+E)
// SC O(V)

vector<int> topoSort(int V, vector<int> adj[]) 
{
    vector<int> ans;
    vector<int> indegree(V, 0);
    
    // Calculate indegrees of all vertices
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            indegree[adj[i][j]] += 1;
        }
    }
    
    queue<int> q;
    
    // Push nodes with 0 indegree into the queue
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        ans.push_back(node);
        
        // Decrease the indegree of all neighbors of the popped node
        for (int i = 0; i < adj[node].size(); i++) {
            int neighbor = adj[node][i];
            indegree[neighbor]--;
            
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
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


     cout << endl << "Topo sort usnig BFS  Kahn’s Algorithm " << endl ;
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

Topo sort usnig BFS  KahnΓÇÖs Algorithm
0 3 2 1
 */