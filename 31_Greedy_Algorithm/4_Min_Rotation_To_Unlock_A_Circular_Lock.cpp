#include <iostream>
using namespace std;
#include <vector>

int rotatiobCount(long long R,long long D){
	int ans =0;
	int first ,second;
	
	while(R){
		first = R%10;
		second = D%10;
		
		R/= 10;
		D/= 10;
		
		ans += min(abs(first-second) , 10-abs(first-second));
	}
	
	return ans;
}

int main(){
	
	cout << rotatiobCount(222,333);
	
	
	return 0;
	
}
