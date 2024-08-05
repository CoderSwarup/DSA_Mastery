#include<iostream>
using namespace std;
#include <bits/stdc++.h>

//Create a Node
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



// TC 
//  Insertion of the Node O(H) 
// Creation of BST O(N2)

// SC O(H)

Node* BSTInsert(Node* root,int target){
    if(root == NULL) {
        Node* temp =new Node(target);
        return temp;
    }

    if(target < root->data){
        root->left = BSTInsert(root->left,target);
    }else{
        root->right = BSTInsert(root->right,target);

    }


    return root;
}

void inOrder(Node* root){
    if(!root) return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);


}

int main(){

    vector<int> arr = {6,3,17,5,11,18,2,1,20,14};

    Node* root = NULL;
    // Create a BSTInsert
    for(int i=0;i<arr.size();i++)
    root = BSTInsert(root,arr[i]);


    // Print
    cout  << "Travese the Inorder " ;
    inOrder(root);

return 0;
}