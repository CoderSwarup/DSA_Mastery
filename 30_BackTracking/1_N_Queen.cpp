#include <iostream>
using namespace std;
#include <vector>


bool checkDia(int n,vector<string> &Board,int i,int j){
	
	// upper left
	int row =i;
	int col = j;
	
	while(row > -1 && col > -1){
		if(Board[row][col] == 'Q')
		{
			return 0;
		}
		
		row--;
		col--;
	}
	
	row = i;
	col = j;
	
	//upper right
	
	while(row > -1 && col < n){
		if(Board[row][col] == 'Q')
		{
			return 0;
		}
		
		row--;
		col++;
	}
	
	return 1;
}

void find(int row,int n,vector<vector<string>> &ans,vector<string> &Board,vector<bool> &column){
	//Base condition
	if(row == n)
	{
		ans.push_back(Board);
	}
	
	//Pun queen at any n position
	for(int j=0;j<n;j++){
		if(column[j] == 0 && checkDia(n,Board,row,j)){
			column[j] = 1;
			Board[row][j] = 'Q';
			
			find(row+1,n,ans,Board,column);
			
			// when return
			column[j] = 0;
			Board[row][j] = '.';
		}
	}
	
	
	
	
}

vector<vector<string>> solveNQueens(int n){
	vector<vector<string>> ans;
	vector<string> Board(n);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			Board[i].push_back('.');
		}
	}
	
	
	vector<bool> column(n,0);
	
	find(0,n,ans,Board,column);
	
	return ans;
}


int main(){
	
	int n = 4;
	vector<vector<string>> ans = solveNQueens(n);
	

	
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<n;j++){
			cout << ans[i][j] << " ";
		}
		cout <<endl;
	}
	
	return 0;
	
}
