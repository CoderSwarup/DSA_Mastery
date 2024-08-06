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


// chek The given tree is binary Tree
// using the Inorder Tracersal

bool isBST(Node* root,int &prev){
    if(!root) return 1;

    if(!isBST(root->left,prev)) return 0;

    if(root->data<=prev) return 0;


    prev = root->data;


    return isBST(root->right,prev);
}


int main(){
    cout << "CReate a Tree to check it BST"<<endl;

    cout << "Enter the Root Node " << "  : ";
    Node* root = BinaryTree();

    cout << endl;

    int prev =INT_MIN;

    cout << "Is BST " << isBST(root,prev);



return 0;
}