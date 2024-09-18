#include <iostream>
using namespace std;
#include <map>

long long int findSubarray(vector<long long int> &arr , int n){
	long long int total = 0;
	//map
	//preffix sum ,count
	unordered_map<long long int,long long int> m;
	long long int PreffixSum = 0;
	m[0] = 1; //initial 
	
	for(int i=0;i<n;i++)
	{
		PreffixSum+= arr[i];
		if(m.count(PreffixSum)){
			total += m[PreffixSum];
			m[PreffixSum]++;
		}else{
			m[PreffixSum] = 1;
		}
	}
	
	
	return total;
	
}

int main(){
	//vector<long long int> arr = {6,-1,-3,4,-2,2,4,6,-12,-2};
	vector<long long int> arr = {0,0,5,5,0,0};
	int n = arr.size();
	
	long long int ans = findSubarray(arr,n);
	cout << ans;
	
	return 0;
}
