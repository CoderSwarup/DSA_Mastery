#include <iostream>
using namespace std;
#include <vector>

class Node{
	public:
	
	int freq;
	char c;
	Node *left, *right;
	
	Node(int frequency,char name){
		freq =frequency;
		c=name;
		left=right=NULL;
	}
};

class comp{
	public:
	bool operator()(Node *a, Node *b){
		// return a->freq < b->freq; // a and b is correct position its ok with sort 
		// but in heap it works reverse
		return a->freq > b->freq;
	}
};

void preorder(Node *root,string &temp, vector<string> &ans){
	
	if(!root)
	return;
	
	if(!root->left && !root->right){
		ans.push_back(temp);
		return;
	}
	
	temp.push_back('0');
	preorder(root->left,temp,ans);
	
	temp.pop_back();
	
	temp.push_back('1');
	preorder(root->right,temp,ans);
	
	temp.pop_back();
	
}


vector<string> huffmanCodes(string s,vector<int> f,int N)
{
	//build huffman tree
	//build a mean heap based on the frequency 
	priority_queue<Node *,vector<Node *> ,comp>pq;
	
	for(int i=0;i<N;i++)
	{
		pq.push(new Node(f[i],s[i]));
	}
	
	while(pq.size() > 1)
	{
		// pop top 2 node
		Node *first = pq.top();
		pq.pop();
		Node *second = pq.top();
		pq.pop();
		
		// create a new Node 
		Node *root = new Node(first->freq+second->freq,'$');
		
		root->left = first;
		root->right = second;
		
		pq.push(root);
	}
	
	Node *root = pq.top();
	pq.pop();
	
	// find the preorder 
	vector<string> ans;
	string temp;
	
	preorder(root,temp,ans);
	
	return ans;
}

int main(){
	
	string s = "abcdef";
	vector<int> f = {5,9,12,13,16,45};
	
	vector<string> ans = huffmanCodes(s,f,s.size());
	
	for(int i=0;i<ans.size();i++)
	{
		cout << ans[i] << " ";
	}
	
	
	return 0;
}
