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


void CountLeafNodeM1(Node* root,int &count){
    if(root == NULL) return;
    
    if(!root->left && !root->right){
        count++;
        return;
    }
    CountLeafNodeM1(root->left,count);
    CountLeafNodeM1(root->right,count);
    
}

int CountLeafNodeM2(Node* root){
    if(root == NULL) return 0;
    
    if(!root->left && !root->right){
        return 1;
    }
    return CountLeafNodeM2(root->left) +    CountLeafNodeM2(root->right);
    
}

int main(){

    cout << "Enter the Root Node " << "  : ";
    Node* root = BinaryTree();


    cout << "Leaf Node In Given Binary Tree : " << endl;


    int count =0;
    CountLeafNodeM1(root,count);
    cout << "Using extra variable : " << count << endl;

    count = CountLeafNodeM2(root);
    cout << "Using Recursion : " << count << endl;


return 0;
}