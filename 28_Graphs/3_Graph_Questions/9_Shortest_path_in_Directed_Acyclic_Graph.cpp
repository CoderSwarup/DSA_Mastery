#include <bits/stdc++.h>
using namespace std;

void DFS(int node, vector<pair<int, int>> adj[], stack<int> &s, vector<bool> &visited) {
    visited[node] = true;
    
    // Look at all its neighbors
    for (int j = 0; j < adj[node].size(); j++) {
        int neighbour = adj[node][j].first;
        
        if (!visited[neighbour]) {
            DFS(neighbour, adj, s, visited);
        }
    }
    
    // Push the current node to the stack after visiting all its neighbors
    s.push(node);
}

vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
    // Create the adjacency list
    vector<pair<int, int>> adj[N];
    
    for (int i = 0; i < M; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];
        
        adj[u].push_back(make_pair(v, weight));
    }
    
    // Topological sort using DFS
    stack<int> s;
    vector<bool> visited(N, false);
    
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            DFS(i, adj, s, visited);
        }
    }
    
    // Distance vector initialized to infinity
    vector<int> dist(N, INT_MAX);
    dist[0] = 0;  // Assuming 0 is the source node
    
    // Process nodes in topological order
    while (!s.empty()) {
        int node = s.top();
        s.pop();
        
        // Update distances to all neighbors
        if (dist[node] != INT_MAX) {
            for (int j = 0; j < adj[node].size(); j++) {
                int neighbour = adj[node][j].first;
                int weight = adj[node][j].second;
                
                if (dist[node] + weight < dist[neighbour]) {
                    dist[neighbour] = dist[node] + weight;
                }
            }
        }
    }
    
    // Replace INT_MAX with -1 for unreachable nodes
    for (int i = 0; i < N; i++) {
        if (dist[i] == INT_MAX) {
            dist[i] = -1;
        }
    }
    
    return dist;
}

int main() {
    int N = 6;  // Number of nodes
    int M = 7;  // Number of edges
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 4, 1},
        {1, 2, 3},
        {4, 2, 2},
        {4, 5, 4},
        {2, 3, 6},
        {5, 3, 1}
    };

    vector<int> shortest_distances = shortestPath(N, M, edges);

    for (int i = 0; i < shortest_distances.size(); i++) {
        cout << "Distance from node 0 to node " << i << ": " << shortest_distances[i] << endl;
    }

    return 0;
}
