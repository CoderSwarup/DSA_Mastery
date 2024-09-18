#include <queue>
using namespace std;
#include<iostream>
#include <vector>

int rows[4]= {1,-1,0,0};
int cols[4]= {0,0,1,-1};


bool valid(int i,int j,int n, int m){
	return i>=0&i<n && j>=0 && j<m;
}

int shortestDestination(int N,int M,vector<vector<int>>A , int X, int Y){
	queue<pair<pair<int,int>,int>> q;
	
	//edge case 
	if(!A[0][0] || (X==0&&Y==0)) return -1;
	
	
	q.push({{0,0},0});
	vector<vector<int>> visited(N,vector<int>(M,0));
	
	visited[0][0]=1;
	
	
	while(!q.empty()){
		int i = q.front().first.first;
		int j = q.front().first.second;
		int step = q.front().second;
		q.pop();
		
		for(int k=0;k<4;k++){
			int new_i = i+rows[k];
			int new_j = j+cols[k];
			
			if(valid(new_i,new_j,N,M) && A[new_i][new_i]&&!visited[new_i][new_j]){
				if(new_i==X && new_j==Y)
				return step+1;
				
				visited[new_i][new_j]=1;
				q.push({{new_i,new_j},step+1});
			}
		}
	}
	
	return -1;
}
int main(){
	
	vector<vector<int>> A ={
		{1,0,0,0},
		{1,1,0,1},
		{0,1,1,1}};
		
	int ans = shortestDestination(3,4,A,2,3);
	cout<< ans;
	
	return 0;
	
}


// how here we xan find step without storing it
//as we level order traversal we can use the traverse in for the level order 
//and after level complete step++
