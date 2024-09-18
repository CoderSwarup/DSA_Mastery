#include <iostream>
using namespace std;
#include <vector>

int assignMiceHoles(int n,int M[],int H[]){
	
	sort(M,M+n);
	sort(H,H+n);
	
	int ans = INT_MIN;
	
	for(int i=0;i<n;i++){
		ans = max(ans,abs(M[i] - H[i]));
	}
	
	return ans;
}
int main(){
	
	int n = 3;
	int M[3] = {4,-4,2};
	int H[3] = {4,0,5};
	
	
	cout << assignMiceHoles(n,M,H);
	
	
	return 0;
	
}
