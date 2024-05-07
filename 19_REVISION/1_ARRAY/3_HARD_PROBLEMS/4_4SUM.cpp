#include <iostream>
using namespace std;
#include <vector>
#include <set>
#include <algorithm>


void printarray(vector<vector<int>> arr ){
	
	int n = arr.size();
	int m = arr[0].size();
	
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout << arr[i][j] << " ";
			}
		cout <<endl;
		}
	
}




vector<vector<int>> foursum(vector<int> arr ,int target){
	
	set<vector<int>> st;
	int n = arr.size();
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				for(int l=k+1;l<n;l++)
				
				    //
					if(arr[i] + arr[j] +arr[k] + arr[l] == target){
				
					vector<int> a = {arr[i] ,arr[j] ,arr[k] , arr[l]};
					sort(a.begin() , a.end());
					st.insert(a);
					}
				}
			}
		}
	
	
	vector<vector<int>> ans(st.begin() , st.end());	
	return ans;	
}
	

vector<vector<int>> foursumBetter(vector<int> arr ,int target){
	
	set<vector<int>> st;
	int n = arr.size();
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			set<int> s;
			for(int k=j+1;k<n;k++){
				int l = target - ( arr[i] + arr[j] + arr[k]);
				if(s.find(l) != s.end()){
					vector<int> temp = { arr[i] , arr[j] , arr[k] , l};
					sort(temp.begin() ,temp.end());
					st.insert(temp);
					
				}
				s.insert(arr[k]);
				}
			}
		}
	
	
	vector<vector<int>> ans(st.begin() , st.end());	
	return ans;	
}

vector<vector<int>> foursumOptimal(vector<int> arr ,int target){
	sort(arr.begin() , arr.end());
	vector<vector<int>> ans;
	int n = arr.size();
	for(int i=0;i<n;i++){
		if(i>0 && arr[i] == arr[i-1]) continue;
		for(int j=i+1;j<n;j++){
			if(j > i+1 && arr[j] == arr[j-1]) continue;
			
			long k = j+1;
			long l = n-1;
			
			while(k<l){
				long long sum = arr[i] + arr[j] + arr[k] + arr[l];
				if(sum<0){
					k++;
					}
					else if(sum >0){
					   l--;
						}else {
						vector<int> temp = {arr[i] , arr[j] ,arr[k] ,arr[l]};
						ans.push_back(temp);
						k++;l--;
						while(k<l && arr[k] == arr[k-1]) k++;
						while(arr[l] == arr[l+1]) l--;
							}
				}
			}
			
		}
	
	
	return ans;	
}
	

int main(){
	
	vector<int> arr= {1,0,-1,0,-2,2};
	
	// vector<vector<int>> ar= foursum(arr, 0);
	// vector<vector<int>> ar= foursumBetter(arr, 0);
	vector<vector<int>> ar= foursumOptimal(arr, 0);

	printarray(ar);
	return 0;
}
