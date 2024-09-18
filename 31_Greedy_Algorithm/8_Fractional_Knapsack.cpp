#include <iostream>
using namespace std;
#include <vector>

struct Item{
	int value;
	int weight;
};

bool comp(Item a,Item b){
	 // here  is value/weight but the follwoing i use for the floating value
	return a.value*b.weight > b.value*a.weight;
}

double fractionalKnapsack(int w,Item arr[], int n){
	
	// sort the arr on the basis of value/weight in the descending order
	sort(arr,arr+n,comp);
	
	
	double profit =0;
	int i=0;
	while(w&& i<n){
		if(w >= arr[i].weight){
			profit += arr[i].value;
			w -= arr[i].weight;
		}else{
			
			// profit += w * arr[i].value/arr[i].weight;
			
			// above give me the wrong ans 
			
			double temp = arr[i].value;
			temp /= arr[i].weight;
			profit += w*temp;
			
			w=0;
		}
		
		i++;
	}
	
	return profit;
	
}


int main(){
	int n = 3;
	int w = 50;
	Item arr[] = {
		{60,10},
		{100,20},
		{120,30}
	};
	
	cout << "Total Profit for the Max Weight " << w << " is : " << fractionalKnapsack(w,arr,n);
	
	return 0;
}
