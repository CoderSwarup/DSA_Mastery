#include <queue>
using namespace std;
#include<iostream>
#include <vector>

// return a cost
int spanningTree(int V, vector<vector<int>> adj[]){
	priority_queue<pair<int, pair<int,int>> , vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
	vector<bool> isMst(V,0);
	
	//the parent not need for the question so if we want to draw the parent tree then is want to use this parent 
	vector<int> parent(V);
	
	int cost =0;
	
	pq.push({0,{0,1}});
	
	while(!pq.empty()){
		
		int wt = pq.top().first;
		int node = pq.top().second.first;
		int parentnode = pq.top().second.second;
		pq.pop();
		if(!isMst[node])
		{
			isMst[node]=1;
			cost += 1;
			parent[node] = parentnode;
			
			for(int i=0;i<adj[node].size();i++){
				
				int neighbour = adj[node][i][0];
				int neighbourweight = adj[node][i][1];
				// the neighbour node is not a part of mst
				if(!isMst[neighbour]){
					pq.push({neighbourweight,{neighbour,node}});
				}
			}
		}
		
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
