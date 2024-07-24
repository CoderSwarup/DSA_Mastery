#include <iostream>
using namespace std;

class Node{
	public:
	int data;
	Node *next;
	Node *prev;
	
	Node(int x){
	
		data = x;
		next = prev = NULL;
		
	}
};

class Dequeue{

	Node *front , *rear;
	public:
	
	Dequeue(){
	
		front = rear=NULL;
	}
	
	void push_front(int x){
	
		if(front==NULL){
		  front = rear = new Node(x);
		  return;
		}else{
			Node *t = new Node(x);
			t->next = front;
			front->prev =t;
			front = t;
		}
	}
	
	
	void push_back(int x){
	
		if(front==NULL){
		  front = rear = new Node(x);
		  return;
		}else{
			Node *t = new Node(x);
			rear->next = t;
			t->prev = rear;
			rear =t;
		}
	}
	
	
	void pop_front(){
		if(front==NULL){
			cout << "dequeue is underflow " << endl;
		}else{
		    cout << "pop element  " << front->data << endl;
		    Node *t = front;
		    front = front->next;
		    delete t;
		    if(front){
		       front->prev = NULL;
		    }else{
		       rear=NULL;
		    }
		}
	}
	
	
	
	void pop_back(){
		if(front==NULL){
			cout << "dequeue is underflow " << endl;
		}else{
			cout << "pop element  " << rear->data << endl;
		    Node *t = rear;
		    rear = rear->prev;
		    delete t;
		    if(rear){
		       rear->next = NULL;
		    }else{
		       front=NULL;
		    }
		}
	}
	
	int start(){
	    if(front==NULL){
	    	cout << "Empty "<<endl;
	    	return -1;
	    }else{
	         return front->data;
	    }
	}
	
	
	int end(){
	    if(front==NULL){
	    	cout << "Empty "<<endl;
	    	return -1;
	    }else{
	         return rear->data;
	    }
	}
};

int main(){

	Dequeue dq;
	dq.push_back(1);
	dq.pop_front();
	dq.push_front(2);
	cout << dq.start() <<endl;
	return 0;
}