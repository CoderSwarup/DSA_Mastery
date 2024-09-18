#include <iostream>
using namespace std;
#include <vector>

struct Job
{
	int id;
	int dead;
	int profit;
};

bool comp(Job a,Job b){
	return a.profit > b.profit;
}

int find(int num,vector<int> &Parent){
	if(num == Parent[num])
	return num;
	
	return Parent[num] = find(Parent[num],Parent);
}

vector<int> jobSequencing(Job arr[],int n){
	
	sort(arr,arr+n,comp);
	
	int deadline =0;
	for(int i=0;i<n;i++)
	deadline = max(deadline,arr[i].dead);
	
	
	//vector<bool> Task(deadline+1,0); // index is ' based 
	vector<int> Parent(deadline+1);
	for(int i=0;i<=deadline;i++)
	{
		Parent[i] = i;
	}
	
	vector<int> ans(2,0); // no of task , profit
	
	/* not optimal
	// pick task 1 by 1
	for(int i=0;i<n;i++){
		
		// can I complee this before or on deadline
		for(int j=arr[i].dead;j>0;j--)
		{
			if(!Task[j]){
				Task[j] = 1;
				ans[0]++;
				ans[1] += arr[i].profit;
				break;
			}
		}
	}
	
	*/
	
	
	for(int i=0;i<n;i++){
		int slot = find(arr[i].dead,Parent);
		if(slot>0)
		{
			ans[0]++;
			ans[1] += arr[i].profit;
			Parent[slot] = slot-1;
		}
	}
	
	return ans;
}

int main(){
	
	Job arr[] = {
		{1,4,20},
		{2,1,10},
		{3,1,40},
		{4,1,30}
	};
	int n = 4;
	
	vector<int> ans = jobSequencing(arr,n);
	cout << "No of Task " << ans[0] << endl;
	cout << "Total Max Profit " << ans[1] << endl;
	return 0;
}
