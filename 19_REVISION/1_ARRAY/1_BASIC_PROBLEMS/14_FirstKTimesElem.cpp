#include <bits/stdc++.h>
using namespace std;


int firstElementKTime(int n, int k, int arr[])
    {
        map<int ,int> hash;
        for(int i=0;i<n;i++){
            hash[arr[i]]++;
            
            if(hash[arr[i]] == k){
                return arr[i];
            }
            
        }
        
        return -1;
        
    }

int main() {

	int n, k;
	cin >> n >> k;
	int a[n];
	for(int i = 0;i<n;i++){
	    cin >> a[i];
	}
	
	cout<<firstElementKTime(n, k, a)<<endl;

	
	return 0;
}