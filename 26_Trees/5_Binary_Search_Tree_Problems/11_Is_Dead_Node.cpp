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


void printInorder(Node *root){
    if(!root) return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);

        
}

bool Dead(Node *root,int lower,int upper){
    
    if(!root) return 0;
    
     if(!root->left && !root->right){
        // check range
        if(root->data-lower==1 && upper-root->data == 1){
            return 1;
        }else{
            return 0;
        }
    }
    
    
    return Dead(root->left,lower,root->data) ||  Dead(root->right,root->data,upper);
}

int main(){
    cout << "Enter the Root Node " << "  : ";
    Node* root = BinaryTree();

    cout << endl << "Your Tree : ";
    printInorder(root);

    cout << endl << "Is Your Node Consist the Dead Node "<< Dead(root,0,INT_MAX);


return 0;
}