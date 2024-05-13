#include<iostream>
using namespace std;
#include <bits/stdc++.h>

int searchInsert(vector<int>& arr, int m)
{
	//Using the cpp algorithm
	// int upper = upper_bound(arr.begin(),arr.end(),m) - arr.begin();
	// int lower = lower_bound(arr.begin(),arr.end(),m) - arr.begin();
	// int index = (lower + upper) /2;
	// return index;

	// also using the lower bound 
	int n = arr.size();

	int low = 0;
	int high = n-1;

	int ans = n;
	while(low <= high){
		int mid = low + ((high - low )/2);
		if(arr[mid] >= m){
			ans = mid;
			high = mid -1;

		}else{
			low = mid +1;
		}
	}

	return ans;
}
int main(){

   vector<int> arr = {1, 2, 4, 7};
  int x = 6;
    int ind = searchInsert(arr, x);
    cout << "Insert AT Position index " << ind << endl;

return 0;
}