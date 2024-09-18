#include <iostream>
using namespace std;
#include <vector>



vector<vector<int>> insertIntervals(vector<vector<int>> &intervals,vector<int> &newInterval){
	
	
	vector<vector<int>> ans;
	
	int i =0;
	int n = intervals.size();
	
	while(i<n && newInterval[0] > intervals[i][1]){
		ans.push_back(intervals[i]);
		i++;
	}
	
	if(i==n){
		ans.push_back(newInterval);
		return ans;
	}
	
	while(i<n && newInterval[1] >= intervals[i][0]){
		
		newInterval[0] = min(newInterval[0],intervals[i][0]);
		newInterval[1] = max(newInterval[1],intervals[i][1]);	
		i++;
	}
	
	ans.push_back(newInterval);
	while(i<n)
	{
		ans.push_back(intervals[i]);
		i++;
		
	}
	
	return ans;
}

int main(){
	vector<vector<int>> intervals = {
		{1,3},
		{6,9}
	};
	
	vector<int> newInterval = {2,5};
	cout << "New Merge Intervals " << endl; 
	
	
	vector<vector<int>> ans = insertIntervals(intervals,newInterval);
	
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[0].size();j++){
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	
	
	return 0;
	
}
