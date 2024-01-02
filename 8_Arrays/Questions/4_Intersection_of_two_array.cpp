#include<iostream>
using namespace std;
#include<vector>

/*
Sample Input 1 :
2
6 4
1 2 2 2 3 4
2 2 3 3
3 2
1 2 3
3 4  
Sample Output 1 :
2 2 3
3  
*/
// UnOptimize approach
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	// Write your code here.
	vector<int> ans;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr1[i] == arr2[j]){
				ans.push_back(arr2[j]);
				arr2[j] = -57;
				break;
			}
		}
	}

	return ans;
}

//Optimize approch
// vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
// {
// 	// Write your code here.
// 	vector<int> ans;
// 	int i = 0 , j=0;
// 	while(i<n&&j<m){

// 		if(arr1[i]==arr2[j]){
// 			ans.push_back(arr1[i]);
// 			i++;
// 			j++;
// 		}
// 		else if(arr1[i]<arr2[j]){
// 			i++;
// 		}else{
// 			j++;
// 		}
// 	}

// 	return ans;
// }
int main(){

    vector<int>arr ={1,2,3,4};
    vector<int>arr1 = {2,3,4};

    vector<int>ans = findArrayIntersection(arr,4,arr1,3);
    for(int i=0;i<ans.size();i++){
        cout << ans[i] <<  " ";
    }

return 0;
}