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


 int find(int in[] ,int target, int InStart,int InEnd){
    
    for(int i=InStart;i<=InEnd;i++){
        if(in[i] == target) return i;
    }
    
    return -1;
}
Node* Tree(int in[],int post[],int InStart , int InEnd, int index){
    
    if(InStart > InEnd) return NULL;
    
    
    Node *root = new Node(post[index]);
    int pos = find(in,post[index],InStart,InEnd);
          
    root->right = Tree(in ,post,pos+1,InEnd,index-1);
    
    
    root->left = Tree(in ,post,InStart,pos-1,index-(InEnd-pos)-1);

    return root;
}
Node *buildTree(int n, int in[], int post[]) {
    // Your code here
    
    return Tree(in,post,0,n-1,n-1);
}

//post Order

void PostOrder(Node* root){
    if(root == NULL) return;

    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}
void InOrder(Node* root){
    if(root == NULL) return;

    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

int main(){ 

    int N = 4;
    int inorder[] = {1, 6 ,8 ,7};
    int postOrder[] = {1 ,6 ,7 ,8};

    Node* root = buildTree(N,inorder,postOrder);

    cout << "PostOrder TREE" << endl;
    PostOrder(root);

    cout << endl << "IN-ORDER TREE" << endl;
    InOrder(root);


return 0;
}