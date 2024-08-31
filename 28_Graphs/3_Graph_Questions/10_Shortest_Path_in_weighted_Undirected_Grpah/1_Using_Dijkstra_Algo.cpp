#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
    // Step 1: Create an adjacency list
    vector<pair<int, int>> adj[n + 1]; // To store (neighbor, weight)
    
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];
        
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }
    
    // Step 2: Initialize data structures
    vector<int> dist(n + 1, INT_MAX); // Distance from source to each node
    vector<int> parent(n + 1, -1);    // To reconstruct the path
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    // Start from node 1
    dist[1] = 0;
    pq.push({0, 1}); // (distance, node)
    
    // Step 3: Dijkstra's Algorithm
    while (!pq.empty()) {
        int currentDist = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        if (currentDist > dist[node]) continue; // Already processed with a shorter distance
        
        for (auto& neighbor : adj[node]) {
            int nextNode = neighbor.first;
            int weight = neighbor.second;
            
            if (dist[node] + weight < dist[nextNode]) {
                dist[nextNode] = dist[node] + weight;
                parent[nextNode] = node;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }
    
    // Step 4: Path reconstruction
    vector<int> path;
    if (dist[n] == INT_MAX) {
        path.push_back(-1); // If the destination is not reachable
        return path;
    }
    
    // Total weight of the shortest path
    int totalWeight = dist[n];
    path.push_back(totalWeight);
    
    // Reconstruct the path from `n` to `1`
    int currentNode = n;
    while (currentNode != -1) {
        path.push_back(currentNode);
        currentNode = parent[currentNode];
    }
    
    // Reverse the path to get it from source to destination
    reverse(path.begin() + 1, path.end());
    
    return path;
}

int main() {
    int n = 5, m = 6;
    vector<vector<int>> edges = {
        {1, 2, 2},
        {2, 5, 5},
        {2, 3, 4},
        {1, 4, 1},
        {4, 3, 3},
        {3, 5, 1}
    };

    vector<int> path = shortestPath(n, m, edges);
    
    // Print the result
    for (int i = 0; i < path.size(); i++) {
        cout << path[i];
        if (i != path.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
