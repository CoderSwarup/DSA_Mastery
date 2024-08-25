#include<iostream>
using namespace std;
#include <bits/stdc++.h>

// TC O(V+E)
// SC O(V)
bool CheckBip(int node,vector<int>adj[],vector<int> &color){
    
    //lok at each neighbour 
    for(int j=0;j<adj[node].size();j++){
        //color not assigned
        if(color[adj[node][j]] == -1){
            color[adj[node][j]] = (color[node]+1) % 2;
            if(!CheckBip(adj[node][j],adj,color)){
                return 0;
            }
        }
        
        
        // Color assigned
        else{
            if(color[adj[node][j]] == color[node]){
                return 0;
            }
        }
    }
    
    return 1;
}
bool isBipartite(int V, vector<int>adj[]){
    // Code here
    
    vector<int>color(V,-1);
    
  
   for(int j=0;j<V;j++){
       if(color[j] == -1){
           color[j] = 0;
           if(!CheckBip(j,adj,color)){
               return 0;
           }
       }
   }
    
    return 1;
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


     cout << endl << "Is Bipartite Graph Using the  DFS " << isBipartite(vertex,AdjList);


return 0;
}

/**
enter the No of Vertex 3 

enter the No of Edges 2
0 1
1 2

Is Bipartite Graph Using the  DFS 1
 */