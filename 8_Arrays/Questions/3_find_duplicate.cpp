#include<iostream>
using namespace std;

int findDuplicate(int arr[], int n){
	// Write your code here.
	int ans = 0;
	for(int i=0;i<n;i++){
      for (int j = i+1; j < n; j++) {
        if(arr[i] ==arr[j]){
            ans =arr[i];
        }
          }
    }

	return ans;
}


int main(){

 int arr[7] = {4,1,2,9,9,6};
   int a=findDuplicate(arr,7);
   cout << a;

return 0;
}