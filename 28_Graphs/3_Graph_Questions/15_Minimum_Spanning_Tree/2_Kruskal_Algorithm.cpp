#include <queue>
using namespace std;
#include<iostream>
#include <vector>


int FindParent(int u, vector<int> &parent){
	if(u == parent[u])
	return u;
	
	return parent[u] = FindParent(parent[u], parent);
	//this step for the path compression
	
}


void UnionByRank(int u, int v ,vector<int> &parent, vector<int> &rank){
	
	int pu = FindParent(u,parent);
	int pv = FindParent(v,parent);
	
	
	// rank , merge
	if(rank[pu] > rank[pv]){
		parent[pv] = pu;
	}else if(rank[pu] < rank[pv]){
		parent[pu] = pv;
	}else{
		parent[pv] = pu;
		rank[pu]++;
	}
	
	
}

int spanningTree(int V, vector<vector<int>> adj[]){
	vector<int> parent(V);// ultimate parent is helps us to determine the set
	vector<int> rank(V,0); // help us to merge the set
	
	for(int i=0;i<V;i++) 
	parent[i] = i;
	
	
	// insert the edges in the sorted  order using priority_queue
	
	
	// tc O(N)
	priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>> , greater<pair<int, pair<int,int>>>>pq;
	
	
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<adj[i].size();j++)
		{
		  pq.push({adj[i][j][1], {i,adj[i][j][0]}});
		}
	}
	
	//here the counter question why use pq why not directly sort the edges 
	
	/*
	vector<pair<int, pair<int,int>>> temp;
	priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>> , greater<pair<int, pair<int,int>>>>pq(temp.begin(),temp.end());
	
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<adj[i].size();j++)
		{
		  temp.push_back({adj[i][j][1], {i,adj[i][j][0]}});
		}
	}
	
	
	here take tc o(E)
	*/
	
	int cost =0;
	int edges = 0;
	
	//cout << pq.size() ;
	while(!pq.empty())
	{
		int wt = pq.top().first;
		int u= pq.top().second.first;
		int v= pq.top().second.second;
		pq.pop();
		
		//check the u and v are in the different set
		if(FindParent(u,parent) != FindParent(v,parent)){
			cost += wt;
			UnionByRank(u,v,parent,rank);
			edges++;
		}
		
		if(edges == V-1)
		break;
	}
	
	
	return cost;
	
}
int main(){
	
	int V =3;
	vector<vector<int>> adj[V];
	
	adj[0].push_back({1,5});
	adj[1].push_back({3,3});
	adj[0].push_back({2,1});
	
	
	int ans = spanningTree(V,adj);
	cout << ans;
	
	return 0;
	
}
