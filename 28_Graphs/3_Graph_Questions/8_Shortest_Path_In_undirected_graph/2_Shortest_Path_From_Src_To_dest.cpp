#include<iostream>
using namespace std;
#include <bits/stdc++.h>


vector<int> shortestPath( vector<pair<int,int>> edges , int N , int M, int src , int dest){
	
	// Write your code here
	    vector<int> adj[N];
        
        for(int i=0;i<M;i++){
            adj[edges[i].first -1].push_back(edges[i].second-1);
            adj[edges[i].second-1].push_back(edges[i].first-1);
        }

		src--;
		dest--;
        
        //Distance
        vector<int> dist(N,-1);
        vector<bool> visited(N,0);
        
        queue<int> q;
        q.push(src);
        dist[src] =0;
        visited[src] =1;
		 vector<int> parent(N,-1);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(int j=0;j<adj[node].size();j++){
                if(visited[adj[node][j]]){
                    continue;
                }
                
                visited[adj[node][j]] =1;
                q.push(adj[node][j]);
                dist[adj[node][j]] = dist[node]+1;
				parent[adj[node][j]] = node;
            }
        }
        
        vector<int>path;
		
		while(dest != -1){
			path.push_back(dest+1);
			dest = parent[dest];
		}
		reverse(path.begin(),path.end());
		return path;
}

// here node are based on the 1 (start from the 1)
int main(){
   vector<pair<int,int>> edges = {{1,1},{1,3},{3,4},{4,5},{5,6},{1,2},{2,6},{6,7},{7,8},{6,8}};
    int N = 10;int M = 10;
    int src = 1;
    int dest = 8;

    vector<int> ans  = shortestPath(edges,N,M,src,dest);

    cout << "Distance from the Source " << src << " To Destination " << dest << " is " << endl;

 for(int i=0;i<ans.size() ;i++){
    cout << ans[i] << " -> " ;
 }
return 1;
}