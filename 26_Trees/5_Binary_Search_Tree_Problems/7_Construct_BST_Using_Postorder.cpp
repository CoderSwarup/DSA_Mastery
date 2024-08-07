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

Node* BST(vector<int>& post,int &index,int lower,int upper){
    if(index < 0 || lower > post[index] || upper < post[index]) return NULL;
    Node* root = new Node(post[index--]);
    root->right = BST(post,index,root->data,upper);
    root->left = BST(post,index,lower,root->data);
    return root;
}
Node* bstFromPostOrder(vector<int>& post) {
        int index =post.size()-1;
        return BST(post,index,INT_MIN,INT_MAX);
        
}


void InOrder(Node* root){
    if(root == NULL) return;

    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

int main(){


    vector<int> postOrder = {8,5,1,7,10,12};
    Node* root = bstFromPostOrder(postOrder);
    InOrder(root);
return 0;
}