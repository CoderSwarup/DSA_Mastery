#include <iostream>
using namespace std;
#include <vector>

bool check(int num, vector<vector<char>> &board,int i,int j){
	char c = '0'+num; // convert to charater 
	
	//check at same row 
	for(int col=0;col<9;col++)
	{
		if(board[i][col] == c)
		{
			return 0;
		}
	}
	
	//check at same col
	
	for(int row=0;row<9;row++)
	{
		if(board[row][j] == c)
		{
			return 0;
		}
	}
	
	//check at same box 3*3
	int row = (i/3) *3;
	int col = (j/3) *3;
	
	for(int a=0;a<3;a++)
	{
		for(int b=0;b<3;b++){
			if(board[a+row][b+col] == c)
			return 0;
		}
	}
	
	return 1;	
}


bool find(int i,int j,vector<vector<char>> &board){
	
	//base case
	if(i== 9)
	return 1;
	
	if(j==9)
	return find(i+1,0,board);
	
	if(board[i][j] != '.')
	return find(i,j+1,board);
	
	
	// check for the empty block
	for(int num=1;num<10;num++){
		
		if(check(num,board,i,j)){
			board[i][j] = '0'+num;
			
			if(find(i,j+1,board))
			return 1;
			
			board[i][j] = '.';
		}
	}
	
	return 0;
}

void solveSudoku(vector<vector<char>> &board){
	find(0,0,board);
}


int main(){
	vector<vector<char>> board(9,vector<char>(9,'.'));
	
	solveSudoku(board);
	
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++){
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
	
}
