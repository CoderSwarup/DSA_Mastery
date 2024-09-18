#include <iostream>
using namespace std;
#include <vector>


int latestInterval(vector<char> &tasks,int n){
	
	// calculate the frquency of each character
	vector<int> frequency(26,0); //A=0 - Z=25
	
	// count is the highest freq char
	int count =0;
	
	for(int i=0;i<tasks.size();i++){
		frequency[tasks[i]-'A']++;
		count = max(count,frequency[tasks[i]-'A']);
	}
	
	int ans = (count-1)*(n+1);
	
	// same frequency chareter add in ans
	for(int i=0;i<26;i++){
		if(frequency[i] == count)
		ans++;
	}
	
	
	return ans > tasks.size() ? ans : tasks.size();
}

int main(){
	
	vector<char> tasks = {'A','A','A','B','B','B'};
	int n = 2;
	cout << latestInterval(tasks,n);
	return 0;
}
