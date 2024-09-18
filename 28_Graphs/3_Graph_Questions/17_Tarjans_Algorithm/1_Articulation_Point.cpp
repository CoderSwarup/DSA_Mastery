#include <queue>
using namespace std;
#include<iostream>
#include <vector>



void DFS(int node, int parent,vector<int> adj[],vector<bool> &visited,vector<int> &disc, vector<int> &low, vector<bool> &artpoint, int &timer){
	
	visited[node] = 1;
	disc[node] = low[node] = timer;
	int child = 0;
	
	for(int i=0;i<adj[node].size();i++){
		int neighb = adj[node][i];
		if(neighb == parent)
		continue;
		else if(visited[neighb]){
			low[node] = min(low[node],disc[neighb]);
		}else
		{
			timer++;
			child++; // for the edge case of the parent node 
			
			
			DFS(neighb,node,adj,visited,disc,low,artpoint,timer);
			
			//check is the articulation point 
			if(disc[node] <= low[node] && parent != -1){
				artpoint[node] = 1;
			}
			
			low[node] = min(low[node],low[neighb]);
		}
	}
	
	
	if(child > 1 && parent == -1)
	{
		artpoint[node] = 1;
	}
}

vector<int> articulationPoint(int V, vector<int> adj[]){
	
	vector<bool> artpoint(V,0);
	vector<int> disc(V);
	vector<int> low(V);
	vector<bool> visited(V,0);
	int timer = 0;
	
	DFS(0,-1,adj,visited,disc,low,artpoint,timer);
	
	vector<int> ans;
	for(int i=0;i<V;i++){
		if(artpoint[i])
		ans.push_back(i);
	}
	
	if(ans.size() == 0)
	{
		ans.push_back(-1);
	}
	
	return ans;
}


int main(){
	
	
	
	int V=5;
	vector<int> adj[V];
	adj[0].push_back(1);
	adj[1].push_back(4);
	adj[2].push_back(4);
	adj[3].push_back(4);
	adj[2].push_back(3);

	
	vector<int> ans = articulationPoint(V,adj);
		
	for(int i=0;i<ans.size();i++)
	{
		cout << ans[i] << " ";
	}
	
	

	
	return 0;
	
}
