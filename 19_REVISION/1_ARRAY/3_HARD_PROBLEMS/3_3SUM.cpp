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



vector<vector<int>> triplatesumbruteForce(vector<int> arr ,int target){
	
	set<vector<int>> st;
	int n = arr.size();
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				if(arr[i] + arr[j] +arr[k] == target){
				
					vector<int> a = {arr[i] ,arr[j] ,arr[k] };
					sort(a.begin() , a.end());
					st.insert(a);
					}
					
				}
			}
		}
	
	
	vector<vector<int>> ans(st.begin() , st.end());	
	return ans;	
}
	


vector<vector<int>> triplatesumBetter(vector<int> arr ,int target){
	
	set<vector<int>> st;
	int n = arr.size();
	for(int i=0;i<n;i++){
		set<int> s;
		for(int j=i+1;j<n;j++){
			int third = -(arr[i]+arr[j]);
			if(s.find(third) != s.end()){
				vector<int> temp = { arr[j] , arr[i] , third};
				
				sort(temp.begin() , temp.end());
				st.insert(temp);
				}
			
			s.insert(arr[j]);
			}
		}
	
	
	vector<vector<int>> ans(st.begin() , st.end());	
	return ans;	
}
	



vector<vector<int>> triplatesumOptimal(vector<int> arr ,int target){
	
	vector<vector<int>> ans;	
	sort(arr.begin() , arr.end());
	for(int i=0;i<arr.size();i++){
	
		if(i >0 && arr[i] ==arr[i-1]) continue;
		
		int j = i+1;
		int k= arr.size()-1;
		
		while(j<k){
		int sum = arr[i] + arr[j] + arr[k] ;
			if(sum <0){
				j++;
			}else if(sum > 0){
				k--;
			}
			else{
				vector<int> t = { arr[i] , arr[j] , arr[k] };
				ans.push_back(t);
				j++;
				k--;
				while(j <k && arr[j] == arr[j-1]) j++;
				while(arr[k] == arr[k+1]) k--;
				
				}
			
			}
		}
	return ans;	
}
	

int main(){
	
	vector<int> arr= {-1 , 0 , 1 , 2 ,-1 ,-4};
	
	// vector<vector<int>> ar= triplatesumbruteForce(arr, 0);
	vector<vector<int>> ar= triplatesumBetter(arr, 0);
	// vector<vector<int>> ar= triplatesumOptimal(arr, 0);
	printarray(ar);
	return 0;
}
