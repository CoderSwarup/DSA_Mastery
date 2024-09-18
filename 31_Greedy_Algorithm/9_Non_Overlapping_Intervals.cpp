#include <iostream>
using namespace std;
#include <vector>

bool comp(vector<int> a,vector<int> b){
	return a[1] < b[1];
}

int earseOverlappingIntervals(vector<vector<int>> &intervals){
	
	// sort the interval basis on the end time
	sort(intervals.begin(),intervals.end(),comp);
	
	int end = INT_MIN;
	int remove =0;
	
	for(int i=0;i<intervals.size();i++){
		if(end<= intervals[i][0])
		{
			end = intervals[i][1];
		}else
		remove++;
	}
	
	return remove;
}

int main(){
	vector<vector<int>> intervals = {
		{1,2},
		{2,3},
		{3,4},
		{1,3}
	};
	
	cout << "No of Intervals remove " << earseOverlappingIntervals(intervals) ;
	
	
	
	return 0;
	
}
