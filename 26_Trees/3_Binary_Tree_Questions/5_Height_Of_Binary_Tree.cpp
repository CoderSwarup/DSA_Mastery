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

int height( Node* node){
        // code here 
        if(node == NULL) return 0;
        
        return 1 + max(height(node->left) , height(node->right));
}

int main(){

    cout << "Enter the Root Node " << "  : ";
    Node* root = BinaryTree();


    cout << endl << "Height of the Binary Tree " << height(root) ;

return 0;
}