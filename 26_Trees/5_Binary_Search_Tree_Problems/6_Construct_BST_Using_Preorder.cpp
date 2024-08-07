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

Node* BST(vector<int>& preorder,int &index,int lower,int upper){
    if(index == preorder.size() || lower > preorder[index] || upper < preorder[index]) return NULL;
    Node* root = new Node(preorder[index++]);
    root->left = BST(preorder,index,lower,root->data);
    root->right = BST(preorder,index,root->data,upper);
    return root;
}
Node* bstFromPreorder(vector<int>& preorder) {
        int index =0;
        return BST(preorder,index,INT_MIN,INT_MAX);
        
}


void InOrder(Node* root){
    if(root == NULL) return;

    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

int main(){


    vector<int> preorder = {8,5,1,7,10,12};
    Node* root = bstFromPreorder(preorder);
    InOrder(root);
return 0;
}