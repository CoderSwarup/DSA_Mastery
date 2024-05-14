#include<iostream>
using namespace std;
#include <bits/stdc++.h>

	int findKRotation(int arr[], int n) {
	    // code here
	    int ans = INT_MAX;
	    int low = 0;
	    int high = n-1;
	    int index = -1;
	    while(low <= high){
	        int mid = low+ ((high-low)/2);
	        
	        if(arr[low] <= arr[high]){
	           if(arr[low] <= ans){
	                index = low;
	                ans = arr[low];
	           }
	            break;
	        }
	        
	        // left sorted
	        if(arr[low] <= arr[mid]){
	            
	            if(arr[low] <= ans){
	                index = low;
	                ans = arr[low];
	            }
	            low = mid+1;
	        }else{
	            
	            if(arr[mid] <= ans){
	                index = mid;
	                ans = arr[mid];
	            }
	            high=mid-1;
	        }
	    }
	    
	    
	    return index;
	}

int main(){

    int arr[] = {4, 5, 6, 7, 0, 1, 2, 3};
    int ans = findKRotation(arr,8);
    cout << "The Count of the Rotation of the Array : " << ans << "\n";
    return 0;

return 0;
}