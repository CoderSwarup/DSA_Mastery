#include <iostream>
using namespace std;
#include <deque>;


int main(){
	
	deque<int>d;
	d.push_front(2);
	d.pop_front();
	
	d.push_front(1);
	cout << d.front() <<endl;
	
	cout << d.back() <<endl;
	return 0;
	
}
