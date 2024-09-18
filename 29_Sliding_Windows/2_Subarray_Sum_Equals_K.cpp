#include <iostream>
using namespace std;
#include <map>

long long int findSubarray(vector<long long int> &arr , int n,int k){
	long long int total = 0;
	//map
	//preffix sum ,count
	unordered_map<long long int,long long int> m;
	long long int PreffixSum = 0;
	m[0] = 1; //initial 
	
	for(int i=0;i<n;i++)
	{
		PreffixSum+= arr[i];
		if(m.count(PreffixSum-k)){
			total += m[PreffixSum-k];
			m[PreffixSum]++;
		}else{
			m[PreffixSum] = 1;
		}
	}
	
	
	return total;
	
}

int main(){

	vector<long long int> arr = {1,1,1};
	int n = arr.size();
	int k = 2;
	
	long long int ans = findSubarray(arr,n,k);
	cout << ans;
	
	return 0;
}
