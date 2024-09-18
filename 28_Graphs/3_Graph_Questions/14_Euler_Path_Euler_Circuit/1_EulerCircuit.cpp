#include <queue>
using namespace std;
#include<iostream>
#include <vector>


	// Euler Circuit  return 2
	// calculate the degree of the each node
	// all node should have even degree
	// all non zero degree node should be connected
	
	
	//Euler path return 1
	// calculate the degree of the each node
	// zero or two node can have odd degree and remaining have even degree
	// all non zero degree node should be connected

void DFS(int node, vector<int> adj[], vector<bool> &visited){
	
	visited[node] = 1;
	for(int i=0;i<adj[node].size();i++){
		if(!visited[adj[node][i]]){
			DFS(adj[node][i],adj,visited);
			
		}
	}
}


int isEulerCircuit(int V, vector<int> adj[]){
	vector<int> deg(V,0);
	int Odd_degree =0;
	
	for(int i=0;i<V;i++){
		deg[i] = adj[i].size();
		if(deg[i]%2)
		Odd_degree++;
	}
	
	if(Odd_degree !=2 && Odd_degree!=0)
	return 0;
	
	// 
	vector<bool> visited(V,0);
	
	for(int i=0;i<V;i++){
		if(deg[i]){
			DFS(i,adj,visited);
			break;
		}
	}
	
	//if non zero degree node still not visited then it not EC or EP
	for(int i=0;i<V;i++){
		if(deg[i] && !visited[i])
		return 0;
	}
	
	// 
	if(Odd_degree == 0){
		return 2;
	}
	else return 1;
}

int main(){
	
	int V = 3;
	vector<int> adj[V];
	
	adj[0].push_back(1);
	adj[0].push_back(2);
	
	adj[1].push_back(0);
	adj[1].push_back(2);
	
	
	adj[2].push_back(0);
	
	adj[2].push_back(1);
	
	cout << isEulerCircuit(V,adj);
	return 0;
}
