#include<iostream>
using namespace std;

#include <bits/stdc++.h> 
// brute force 
// TC (M*N)
// SC (n)
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	vector<int> visited(m);
    vector<int> ans;

    //
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) {
            if(arr1[i] == arr2[j] && visited[j] ==0){
                ans.push_back(arr1[i]);
                visited[j] = 1;
                break;
            }

            if(arr1[i] < arr2[j]) break; 
        }
    }

    return ans;
}


// OPTIMAL 
//TC (m+n)
vector<int> findArrayIntersectionOptimal(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	// Write your code here.
	vector<int> ans;
	int i = 0 , j=0;
	while(i <n && j<m){
        if(arr1[i] == arr2[j]){
            ans.push_back(arr1[i]);
            i++;
            j++;
        }else if(arr1[i] > arr2[j]){
            j++;
        }else{
            i++;
        }
    }

	return ans;
}
int main(){

    vector<int>a ={ 1 ,2 ,2 ,2 ,3, 4};
    vector<int>b = {2 ,2 ,3 ,3};


    // vector < int > ans = findArrayIntersection(a,a.size(),b,b.size());
    vector < int > ans = findArrayIntersectionOptimal(a,a.size(),b,b.size());
    cout << "Intersection of arr1 and arr2 is  " << endl;
    for (auto val: ans)
    cout << val << " ";



return 0;
}