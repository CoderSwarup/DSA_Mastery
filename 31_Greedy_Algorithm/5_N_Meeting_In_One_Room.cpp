#include <iostream>
using namespace std;
#include <vector>


bool comp(pair<int,int> a,pair<int,int> b){
	return a.second < b.second;
}

int nMeetings(int start[] ,int end[],int n){
	
	// sort the basis on end tine in ascending order
	
	vector<pair<int,int>> timer;
	
	for(int i=0;i<n;i++){
		timer.push_back({start[i],end[i]});
	}
	
	
	sort(timer.begin(),timer.end(),comp);
	
	int total = 0;
	
	int LasteEdingMeeting = -1;
	
	
	for(int i=0;i<n;i++){
		if(timer[i].first > LasteEdingMeeting)
		{
			total++;
			LasteEdingMeeting = timer[i].second;
		}
	}
	
	
	return total;
}

int main(){
	
	int n = 6;
	int start[6] = {1,3,0,5,8,5};
	int end[6] = {2,4,6,7,9,9};
	
	cout << nMeetings(start,end,n);
	
	
	return 0;
}
