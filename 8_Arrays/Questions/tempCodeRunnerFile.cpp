vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	// Write your code here.
	vector<int> ans;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr1[i] == arr2[j]){
				ans.push_back(arr2[j]);
				arr2[j] = -57686;
				break;
			}
		}
	}

	return ans;
}
