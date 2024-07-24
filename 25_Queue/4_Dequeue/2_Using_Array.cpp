#include <iostream>
using namespace std;


class Dequeue{
	int front , rear , size ;
	int *arr;

	public:
	
	Dequeue(int s){
		size = s;
		arr = new int[size];
		front=rear =-1;
	
	}
	bool isempty(){
		return front==-1;
	}
	
	bool isfull(){
		return (rear+1)%size == front;
	}
	void push_front(int x){
	    if(isempty()){
	    	cout << "Elem " << x << " is push from front "<<endl;
	    	front = rear = 0;
	    	arr[0] = x;
	    	return;
	    }else if(isfull()){
	    	cout << "dequeue is overflow" << endl;
	    	return;
	    }else{
	   	cout << "Elem " << x << " is push from front "<<endl;
	    	front = (front-1+size)%size;
	    	arr[front] = x;
	    	return;
	    }
	}
	
	void push_back(int x){
	    if(isempty()){
	    	cout << "Elem " << x << " is push from back"<<endl;
	    	front = rear = 0;
	    	arr[0] = x;
	    	return;
	    }else if(isfull()){
	    	cout << "dequeue is overflow" << endl;
	    	return;
	    }else{
	    	
	    cout << "Elem " << x << " is push from back"<<endl;
	    	rear = (rear+1)%size;
	    	arr[rear] = x;
	    	return;
	    }
	}
	
	
	void pop_front(){
		if(isempty()){
			cout << "is underflow "<<endl;
			return;
		}else{
			if(front==rear){
				cout << " pop element  is : "<< arr[front] << endl;
			    front = rear = -1;
			}else{
				cout << " pop element  is : "<< arr[front] << endl;
				front = (front-1+size)%size;
			}
		}
	}
	
	void pop_back(){
		if(isempty()){
			cout << "is underflow "<<endl;
			return;
		}else{
			if(front==rear){
				cout << " pop element  is : "<< arr[rear] << endl;
			    front = rear = -1;
			}else{
				cout << " pop element  is : "<< arr[rear] << endl;
				front = (rear+1)%size;
			}
		}
	}
	
	
	int start(){
		if(isempty()){
			cout << "is empty "<<endl;
			return -1;
		}else{
			return arr[front];
		}
	}
	
	
	int end(){
		if(isempty()){
			cout << "is empty "<<endl;
			return -1;
		}else{
			return arr[rear];
		}
	}
};

int main(){

	Dequeue dq(5);
	dq.push_back(1);
	dq.pop_front();
	dq.push_front(2);
	cout << dq.start() <<endl;
	
	dq.pop_front();
	cout << dq.start() <<endl;
	return 0;
}