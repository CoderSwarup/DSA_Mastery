#include <iostream>
using namespace std;
#include <map>

// here mod ans based on the your compiler
//ex -3 % 7 = -3 || +4

/*


num => a * b + rem
-3  =  7 * 0 - 3
-3  =  7 * -1 + 4
*/
long long int findSubarrayDividedByK(vector<long long int> &arr , int n,int k){	//map // also use the vector as we know rem shold be 0 to k-1 
	//reminder ,count
	
	unordered_map<long long int,long long int> m;
	long long int PreffixSum = 0;
	long long int total = 0;
	long long int rem;
	
	m[0] = 1; //initial 
	
	for(int i=0;i<n;i++)
	{
		PreffixSum+= arr[i];
		rem = PreffixSum % k;
		//if(rem < 0) // if rem  negative make it positive 
		//rem = k + rem;
		
		//as above rem handle
		rem = (PreffixSum % k + k)%k;
		
		/*
		if(m.count(rem)){
			total += m[rem];
			m[rem]++;
		}else{
			m[rem] = 1;
		}
		*/
		
		// work as above because if not exist in map they return 0
		total += m[rem];
		m[rem]++;
	}
	
	
	return total;
	
}

int main(){

	vector<long long int> arr = {4,5,0,-2,-3,1};
	int n = arr.size();
	int k = 5;
	
	long long int ans = findSubarrayDividedByK(arr,n,k);
	cout << ans;
	
	return 0;
}
