#include <queue>
using namespace std;
#include<iostream>
#include <vector>

void DFS(int node, int parent ,vector<vector<int>>  &adj,vector<int> &disc,vector<int> &low, vector<bool> &visited,vector<vector<int>> &Bridges,int &count)
{
	disc[node] = count;
	low[node] = count;
	
	visited[node] = 1;
	
	for(int j=0;j<adj.size();j++){
		int neighb = adj[node][j];
		if(neighb == parent)
		{
			continue;
		}else if(visited[neighb]){
			low[node] = min(low[node],low[neighb]);
		}else{
		   count++;
		   
		   DFS(neighb,node,adj,disc,low,visited,Bridges,count);
		   
		   
		   // bridge exist
		   if(disc[node] < low[neighb])
		   {
		   	  vector<int> temp;
		   	  temp.push_back(node);
		   	  temp.push_back(neighb);
		   	  Bridges.push_back(temp);
		   }
		   
		   low[node] = min(low[node],low[neighb]);
		   
		   
		}
	}
}




vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections ){
	
	vector<vector<int>>  adj(n);
	
	for(int i=0;i<connections.size();i++){
		int u = connections[i][0];
		int v = connections[i][1];
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	vector<vector<int>> Bridges;
	vector<int> disc(n);
	vector<int> low(n);
	vector<bool> visited(n,0);
	
	int count =0;
	
	DFS(0,-1,adj,disc,low,visited,Bridges,count);
	
	return Bridges;
	
	
}


int main(){
	
	
	
	int n =4;
	vector<vector<int>> connections = {
		{0,1},{1,2}
		};
	
	vector<vector<int>> bridges = criticalConnections(n,connections);
		
	for(int i=0;i<bridges.size();i++)
	{
		for(int j=0;j<bridges[i].size();j++){
			cout << bridges[i][j] << " -> ";
		}
		
		cout << endl;
	}
	
	
	
     cout << "hel";
	
	return 0;
	
}
