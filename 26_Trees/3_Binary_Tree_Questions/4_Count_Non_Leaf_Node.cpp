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


void CountNonLeafNodeM1(Node* root,int &count){
    if(root == NULL) return;

    if(root->left || root->right){
        count++;
    }
    CountNonLeafNodeM1(root->left,count);
    CountNonLeafNodeM1(root->right,count);

}

int CountNonLeafNodeM2(Node* root){
    if(root == NULL) return 0;
    
    if(!root->left && !root->right){
        return 0;
    }
    
    
    return 1 + CountNonLeafNodeM2(root->left) + CountNonLeafNodeM2(root->right);
}


int main(){

    cout << "Enter the Root Node " << "  : ";
    Node* root = BinaryTree();


    cout << "Non Leaf Node In Given Binary Tree : " << endl;


    int count =0;
    CountNonLeafNodeM1(root,count);
    cout << "Using extra variable : " << count << endl;

    count = CountNonLeafNodeM2(root);
    cout << "Using Recursion : " << count << endl;


return 0;
}