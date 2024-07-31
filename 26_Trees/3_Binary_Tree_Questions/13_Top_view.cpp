#include<iostream>
using namespace std;
#include <bits/stdc++.h>

class Node{
    public:
    int data;
    Node *left , *right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* BinaryTree(){
    int x ;
    cin >> x;
    if(x == -1){
        return NULL;
    }

    //Create a Node 
    Node* temp =new  Node(x);

    //Left Side
    cout << "Enter The Left Child of the " << x << " : " ;
    temp->left = BinaryTree();
    //Right Side
    cout << "Enter The Right Child of the " << x << " : " ;
    temp->right = BinaryTree();


    return temp;
}


void findLeftRightMost(Node* r,int pos , int &l,int &right){
	if(!r) return;
	
	l = min(l,pos);
	right= max(right,pos);
	
	findLeftRightMost(r->left,pos-1,l,right);
	findLeftRightMost(r->right,pos+1,l,right);
	
}



	//using level order
	

vector<int> topview(Node *root){
	int l = 0;
	int r= 0;
	findLeftRightMost(root,0,l,r);
	
	vector<int> ans(r-l+1);
	vector<int> filled(r-l+1);
	
	queue<Node*> q;
	queue<int> index;
	
	q.push(root);
	index.push(-1*l);
	
	while(!q.empty()){
		Node *t = q.front();
		q.pop();
		int pos = index.front();
		index.pop();
		
		if(!filled[pos]){
			filled[pos] = 1;
			ans[pos] = t->data;
		}
		
		if(t->left){
			q.push(t->left);
			index.push(pos-1);
		}
		
		if(t->right){
			q.push(t->right);
			index.push(pos+1);
		}
	}
		
}

	
//using recursion
	
void TViewRecursion(Node *root , int pos , vector<int> &ans , vector<int>&level, int l){
	if(!root) return;
	
	if(level[pos] > l){
		ans[pos] = root->data;
		level[pos] = l;
	}
	TViewRecursion(root->left,pos-1,ans,level,l+1);
    TViewRecursion(root->right,pos+1,ans,level,l+1);
	
	
}
	
vector<int> topviewrecursion(Node *root)
{
	int l = 0 ;
	int r = 0;
	findLeftRightMost(root,0,l,r);
	
	vector<int> ans(r-l+1);
	vector<int> level(r-l+1,INT_MAX);
	
		
	TViewRecursion(root->left,-1*l,ans,level,0);
}


int main(){

    cout << "Enter the Root Node " << "  : ";
    Node* root = BinaryTree();

	cout << endl << "Top view of the Binary Tree using Top level ";
	
	vector<int> ans =topview(root);

	for(int i=0;i<ans.size() ;i++){
		cout << ans[i] << " ";
	}


return 0;
}