#include <iostream>
using namespace std;
#include <vector>


bool find(int node,vector<int> &color,bool graph[101][101],int m,int n){
	
	// base condition
	if(node == n)
	return 1;
	
	//Try each color 1 by 1
	for(int i=0;i<m;i++){
		
		//No adjacent node should have this color
		bool IsPossible = 1;
		for(int j=0;j<n;j++){
			
			// check is node adj and color
			if(graph[node][j] && color[j]==i){
				IsPossible =0;
				break;
			}
		}
	
		if(IsPossible)
		{
			//assing color to the node
			color[node] = i;
			
			// check the nezt node 
			if(find(node+1,color,graph,m,n))
			return 1;
					
			color[node] = -1;
		}
		
	}
	
	
	return 0;
}
bool graphColoring(bool graph[101][101],int m,int n){
	// edge case the graph should be disconnected
	
	vector<int> color(n,-1); 
	return find(0,color,graph,m,n);
	
}

int main(){
	int m = 3;
	int n = 4;
	bool graph[101][101];
	
	
	graph[0][1] =1;
	graph[1][2] =1;
	graph[2][3] = 1;
	graph[3][0] = 1;
	graph[0][2] = 1;
	
	
	cout << graphColoring(graph,m,n);
	
	return 0;
}
