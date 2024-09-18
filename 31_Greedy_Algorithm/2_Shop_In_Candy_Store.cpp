#include <iostream>
using namespace std;
#include <vector>

vector<int> candyStore(vector<int> &candies,int N,int K){
	
	// sort the candies 
	sort(candies.begin() , candies.end());
	
	int minAmount = 0;
	int maxAmount = 0;
	
	int i=0;
	int j = N-1;
	
	while(i<=j){
		minAmount += candies[i];
		i++;
		
		j -= K;
	}
	
	
	// for max 
	i = N-1;
	j=0;
	
	while(i>=j){
		maxAmount += candies[i];
		i--;
		
		j+=K;
	}
	
	return {minAmount , maxAmount};
}

int main(){
	int N = 5;
	int K = 2; // no of candies buy for free 
	vector<int> candies = {5,3,1,2,4};
	
	vector<int> ans = candyStore(candies,N,K);
	
	cout << "Min Cost " << ans[0] << endl;
	cout << "Max Cost " << ans[1] << endl;
	
	return 0;
}
