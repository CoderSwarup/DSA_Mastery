#include <iostream>
using namespace std;
#include <vector>

vector<int> minPartition(int N){
	vector<int> currency = {2000,500,200,100,50,20,5,2,1};
	
	int notes = 0;
	int i =0;
	
	vector<int> ans;
	while(N){
		notes = N/currency[i];
		
		while(notes--)
		{
			ans.push_back(currency[i]);
		}
		
		N %= currency[i];
		i++;
	}
	
	
	return ans;
	
}

int main(){
	
	int N = 43;
	
	vector<int> ans = minPartition(N);
	
	for(int i=0;i<ans.size();i++){
		cout << ans[i] << " ";
	}
	
	
	return 0;
}
