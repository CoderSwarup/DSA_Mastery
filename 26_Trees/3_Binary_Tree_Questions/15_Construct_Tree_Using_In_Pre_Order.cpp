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
Node* Tree(int in[],int pre[],int InStart , int InEnd, int index){
    
    if(InStart > InEnd) return NULL;
    
    
    Node *root = new Node(pre[index]);
    int pos = find(in,pre[index],InStart,InEnd);
    
    
    root->left = Tree(in ,pre,InStart,pos-1,index+1);
    
    root->right = Tree(in ,pre,pos+1,InEnd,index+(pos-InStart)+1);
    
    return root;
}
Node* buildTree(int in[],int pre[], int n)
{
    // Code here
    return Tree(in,pre,0,n-1,0);
}

//preOrder

void PreOrder(Node* root){
    if(root == NULL) return;

    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}
void InOrder(Node* root){
    if(root == NULL) return;

    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

int main(){ 

    int N = 6;
    int inorder[] = {3 ,1 ,4 ,0 ,5, 2};
    int preorder[] = {0 ,1 ,3, 4, 2, 5};

    Node* root = buildTree(inorder,preorder,N);

    cout << "PREORDER TREE" << endl;
    PreOrder(root);

    cout << endl << "IN-ORDER TREE" << endl;
    InOrder(root);


return 0;
}