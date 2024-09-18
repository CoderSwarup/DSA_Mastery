#include <queue>
using namespace std;
#include<iostream>
#include <vector>

int rows[8]= {2,2,-2,-2,1,-1,1,-1};
int cols[8]= {1,-1,1,-1,2,2,-2,-2};


bool valid(int i,int j,int n, int m){
	return i>=0&i<n && j>=0 && j<m;
}

int minStepToReachTarget(vector<int> knightPos,vector<int> targetPos,int N){
	
	if(knightPos[0] == targetPos[0]&& knightPos[1] ==targetPos[1])
	return 0;
	knightPos[0]--;
	knightPos[1]--;
	targetPos[0]--;
	targetPos[1]--;
	queue<pair<int,int>>q;
	vector<vector<bool>> chess(N,vector<bool>(N,0));
	q.push({knightPos[0],knightPos[1]});
	
	chess[knightPos[0]][knightPos[1]] = 1;
	
	int step =0;
	
	while(!q.empty()){
		int count = q.size();
		
		while(count--){
		  int i = q.front().first;
		  int j = q.front().second;
		  q.pop();
		  
		  
		  for(int k=0;k<8;k++){
			int new_i = i+rows[k];
			int new_j = j+cols[k];
			
			if(valid(new_i,new_j,N,N) && !chess[new_i][new_j]) {
				if(new_i==targetPos[0] && new_j==targetPos[1])
				return step+1;
				chess[new_i][new_j] =1;
				q.push({new_i,new_j});
			}
		  }
		  
		  
		}
		
		step++;
	}
	
	
	return -1;
}

//index 1 based
int main(){
	
	vector<int> knightPos = {4,5} ;
	vector<int> targetPos= {1,1} ;
	int n = 6;
	
	int ans =minStepToReachTarget(knightPos	,targetPos,n);
	
	cout << ans;
	
	return 0;
	
}

