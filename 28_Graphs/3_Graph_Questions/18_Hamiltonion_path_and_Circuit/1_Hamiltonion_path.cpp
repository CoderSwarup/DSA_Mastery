#include <iostream>
using namespace std;
#include <vector>

// TC O(N!)

bool DFS(int node ,vector<vector<int>> &adj, vector<bool> &visited,int &count, int N){
	
	visited[node]=1;
	count++;
	
	if(count == N) return 1;
	
	for(int j=0;j<adj[node].size();j++)
	{
		if(!visited[adj[node][j]] && DFS(adj[node][j],adj,visited,count,N))
		return 1;		
	}
	
	visited[node] = 0;
	count--;
	
	return 0;
	
}

// vertex start from 1 

bool check(int N,int M,vector<vector<int>> edges){
	
	// create adj list
	vector<vector<int>> adj(N);
	
	for(int i=0;i<M;i++){
		adj[edges[i][0]-1].push_back(edges[i][1]-1);
		adj[edges[i][1]-1].push_back(edges[i][0]-1);
	}
	
	
	vector<bool> visited(N,0);
	int count =0;
	
	for(int i=0;i<N;i++)
	{
		int ans = DFS(i,adj,visited,count,N);
		if(ans) return 1;
	}
	
	return 0;
}


int main(){
	
	int N =4;
	int M =4;
	
	vector<vector<int>> edges= {
		{1,2},
		{2,3},
		{3,4},
		{2,4}
	};
	
	int ans = check(N,M,edges);
	cout << "Is Hamiltonion Path : " << ans;
	
	return 0;
}
