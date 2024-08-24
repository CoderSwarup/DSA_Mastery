#include<iostream>
using namespace std;
#include <bits/stdc++.h>

// TC O(V+E)
// SC O(V)
    bool isCyclic(int V, vector<int> adj[]) {
        // Code here
        vector<int> indegree(V,0);
  
        for(int i=0;i<V;i++){
           for(int j=0;j<adj[i].size();j++){
               indegree[adj[i][j]] +=1;
           }
        }
        
        queue<int>q;
        
        for(int i=0;i<indegree.size();i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        // vector<int>ans;
        int count= 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            // ans.push_back(node);
            
            
            for(int j=0;j<adj[node].size();j++){
                indegree[adj[node][j]]--;
                
                if(indegree[adj[node][j]] == 0){
                    q.push(adj[node][j]);
                }
            }
        }
        
        // int count = ans.size();
        
        
        return count!=V;
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


     cout << endl << "Is Cycle Detect Using the  BFS " << isCyclic(vertex,AdjList);


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