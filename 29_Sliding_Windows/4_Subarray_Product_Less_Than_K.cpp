#include <iostream>
using namespace std;
#include <map>
int Subarray_ProductLessThanK(vector<int> &arr,int n,int k){
	
	int product =1 , start=0, end = 0;
	int total =0;
	
	while(end < n){
		product *= arr[end];
		
		while(product >= k && start <= end){
			product /= arr[start];
			start++;
		}
		total += 1+ (end-start);
		
		end++;
	}
	
	return total;
}


int main(){
	
	vector<int> arr = {1,2,3};
	int n = arr.size();
	int k = 0;
	
    int ans = Subarray_ProductLessThanK(arr,n,k);
	cout << ans;
	
	return 0;
}
