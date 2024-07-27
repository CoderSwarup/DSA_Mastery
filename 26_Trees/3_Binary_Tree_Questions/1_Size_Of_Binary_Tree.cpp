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


// Method 1 using extra variable

void SizeofBinaryTreeM1(Node* root, int &count){
    if(root==NULL) return;
    
    count++;
    SizeofBinaryTreeM1(root->left,count);
    SizeofBinaryTreeM1(root->right,count);
}

// Method 2 using Recursion 
int SizeofBinaryTreeM2(Node* root){
    if(root==NULL) return 0;
    
    return 1 + SizeofBinaryTreeM2(root->left) + SizeofBinaryTreeM2(root->right);
}
    

int main(){
    cout << "Enter the Root Node " << "  : ";
    Node* root = BinaryTree();

    cout << endl << "Size of the Binary TREE " << endl;

    int count =0;
    SizeofBinaryTreeM1(root,count);
    cout << "Using extra variable : " << count << endl;

    count = SizeofBinaryTreeM2(root);
    cout << "Using Recursion : " << count << endl;




return 0;
}