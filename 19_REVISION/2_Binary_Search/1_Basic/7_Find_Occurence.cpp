//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


		
int FirstOccurence(int arr[],int n,int key){
    int Findex = 0;
    int Lindex = n-1;
    int mid = Findex +(Lindex - Findex)/2;
    int ans = -1;
    while(Findex <=Lindex){
        if(arr[mid] == key){
            ans = mid;
            Lindex = mid - 1; 
        }

        if(arr[mid] < key){
            Findex = mid + 1;
        }

        if(arr[mid] > key){
            Lindex = mid-1;
        }
        mid = Findex +(Lindex - Findex)/2;
    }


    return ans;
}


int LastOccurence(int arr[],int n,int key){
    int Findex = 0;
    int Lindex = n-1;
    int mid = Findex +(Lindex - Findex)/2;
    int ans = -1;
    while(Findex <= Lindex){
        if(arr[mid] == key){
            ans = mid;
           Findex = mid +1;
        }

        if(arr[mid] < key){
            Findex = mid + 1;
        }

        if(arr[mid] > key){
            Lindex = mid-1;
        }
        mid = Findex +(Lindex - Findex)/2;
    }


    return ans;
}
int count(int arr[], int n, int x) {
	    // code here
	    int fo = FirstOccurence(arr,n,x);
	    if(fo == -1) return 0;
	    int lo = LastOccurence(arr,n,x);
	    
	    int ans = lo - fo +1;
	    
	    return ans ;
	    
	    
}


//{ Driver Code Starts.

int main() {
    
    int arr[4] = {0,1,1,2};
    int n = sizeof(arr)/sizeof(int);
    int k = 1;
     
     cout << count(arr,n,k);

    return 0;
}

