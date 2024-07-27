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

void SumofBinaryTreeM1(Node* root, int &sum){
    if(root==NULL) return;
    
    sum += root->data;
    SumofBinaryTreeM1(root->left,sum);
    SumofBinaryTreeM1(root->right,sum);
}

// Method 2 using Recursion 
int SumofBinaryTreeM2(Node* root){
    if(root==NULL) return 0;
    
    return root->data + SumofBinaryTreeM2(root->left) + SumofBinaryTreeM2(root->right);
}
    

int main(){
    cout << "Enter the Root Node " << "  : ";
    Node* root = BinaryTree();

    cout << endl << "Sum of the Binary TREE " << endl;

    int sum =0;
    SumofBinaryTreeM1(root,sum);
    cout << "Using extra variable : " << sum << endl;

    sum = SumofBinaryTreeM2(root);
    cout << "Using Recursion : " << sum << endl;




return 0;
}