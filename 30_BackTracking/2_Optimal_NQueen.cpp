#include <iostream>
using namespace std;
#include <vector>


void find(int row,int n,vector<vector<string>> &ans,vector<string> &Board,vector<bool> &column,vector<bool> &leftDia,vector<bool>&rightDia){
	//Base condition
	if(row == n)
	{
		ans.push_back(Board);
	}
	
	//Pun queen at any n position
	
	// left diagonal  n-1 + col - row
	// right diagonal row + col
	
	
	for(int j=0;j<n;j++){
		if(column[j] == 0 && leftDia[n-1+j-row] == 0 && rightDia[row+j] == 0){
			
			column[j] = 1;
			Board[row][j] = 'Q';
			leftDia[n-1+j-row] = 1;
			rightDia[row+j] = 1;
			
			
			find(row+1,n,ans,Board,column,leftDia,rightDia);
			
			// when return
			column[j] = 0;
			Board[row][j] = '.';
			leftDia[n-1+j-row] = 0;
			rightDia[row+j] = 0;
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
	
	
	vector<bool> leftDia(2*n-1,0);
	vector<bool> rightDia(2*n-1,0);
	
	vector<bool> column(n,0);
	
	find(0,n,ans,Board,column,leftDia,rightDia);
	
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
