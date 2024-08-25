#include<iostream>
using namespace std;
#include <bits/stdc++.h>

// TC O(V+E)
// SC O(V)
bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    
	    vector<int>color(V,-1);
	    queue<int> q;
	    
	   for(int j=0;j<V;j++){
	       if(color[j] == -1){
	            q.push(j);
        	    color[j] =0;
        	    
        	    
        	    while(!q.empty()){
        	        int node = q.front();
        	        q.pop();
        	        
        	        for(int i=0;i<adj[node].size();i++){
        	            //Color not assigned
        	            if(color[adj[node][i]] == -1){
        	                color[adj[node][i]] = (color[node]+1) % 2;
        	                q.push(adj[node][i]);
        	            }
        	            //Color is Already assigned
        	            else{
        	                if(color[adj[node][i]] == color[node]){
        	                    return 0;
        	                }
        	            }
        	        }
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


     cout << endl << "Is Bipartite Graph Using the  BFS " << isBipartite(vertex,AdjList);


return 0;
}

/**
enter the No of Vertex 3

enter the No of Edges 3
0 1
1 2
2 0

Is Bipartite Graph Using the  BFS 0
 */