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

Node* LCA(Node *root, int n1, int n2)
    {
        // code here
        if(!root) return NULL;
        
        if(root->data>n1 && root->data>n2){
            return LCA(root->left,n1,n2);
        }else if(root->data<n1 && root->data<n2){
            return LCA(root->right,n1,n2);
        }else{
            return root;
        }
}



int main(){
    cout << "Enter the Root Node " << "  : ";
    Node* root = BinaryTree();


    cout << endl << "Your Tree : ";
    printInorder(root);

    int n1 ,n2;
    cout << endl << "Enter The N1 Value ";
    cin >> n1;
    cout << endl << "Enter The N2 Value ";
    cin >> n2;

    root = LCA(root,n1,n2);
    cout << endl <<  "Lowest Common Ancestor :: " << root->data;


return 0;
}