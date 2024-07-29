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



void mirror(Node* node) {
        // code here
        if(node == NULL) return;
        
        Node* temp = node->right;
        node->right = node->left;
        node->left = temp;
        
        mirror(node->left);
        mirror(node->right);
       
}

void PreOrder(Node* root){
    if(root == NULL) return;

    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}


int main(){

    cout << "Enter the Root  Node " << "  : ";
    Node* root = BinaryTree();


    cout << endl;

    cout << "Before Mirrror : " ;
    PreOrder(root);
   

    mirror(root);


    cout << endl << "After Mirror : " ;
    PreOrder(root);
return 0;
}