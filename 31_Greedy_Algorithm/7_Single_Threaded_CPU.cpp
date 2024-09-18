#include <iostream>
using namespace std;
#include <vector>


vector<int> getOrder(vector<vector<int>> &tasks){
	vector<int> ans;
	int n = tasks.size();
	
	// insert it sequence,   index
	for(int i=0;i<n;i++)
	tasks[i].push_back(i);
	
	// sort the task on the basis of enqeue
	sort(tasks.begin(),tasks.end());
	
	long long timer = tasks[0][0]; //
	
	int i=0;
	
	// min heap => processing time , index
	priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
	
	
	while(!pq.empty() || i<n)
	{
		// put all the taks into min heap whose enqueue time is less than or equal timer 
	    while(i<n && timer >= tasks[i][0]){
	    	pq.push({tasks[i][1],tasks[i][2]});
	    		i++;
	    }
	    // if min heap enpty 
	    if(pq.empty())
	    {
	    	timer = tasks[i][0];
	    }
	
	   // not empty 
	
	    else{
	    	ans.push_back(pq.top().second);
	    	timer += pq.top().first;
	    	pq.pop();
	    }
	}
	
	return ans;
}

int main(){
	vector<vector<int>> tasks = {
		{1,2},
		{2,4},
		{3,2},
		{4,1}
	};
	
	
	vector<int> ans = getOrder(tasks);
	
	for(int i=0;i<ans.size();i++){
		cout << ans[i] << " ";
	}
	return 0;
}
