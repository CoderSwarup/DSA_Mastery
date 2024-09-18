#include <iostream>
using namespace std;
#include <vector>


bool DFS(int node,vector<int> &color,bool graph[101][101],int m,int n){
	
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
		
		
		if(IsPossible==0)
		{
			continue;
		}
		
		//assing color to the node
		color[node] = i;
		
		IsPossible = 1;
		// go to adjacent node whom the color is not assign
		for(int j=0;j<n;j++){
			if(graph[node][j] && color[j]==-1){
				 // if not color assing 
				 if(!DFS(j,color,graph,m,n)){
				 	IsPossible = 0;
				 	break;
				 }
			}
		}
		
		// if all the adj node can be colored then ispossible is 1
		if(IsPossible==1)
		{
			return 1;
		}
		
		// chnage the color
		color[node] = -1;
	}
	
	
	return 0;
}
bool graphColoring(bool graph[101][101],int m,int n){
	// edge case the graph should be disconnected
	
	vector<int> color(n,-1); 
	for(int i=0;i<n;i++)
	{
	   if(color[i] == -1 && !DFS(0,color,graph,m,n)){
			return 0;
		}
	}
	
	return 1;
	
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