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



bool isIdentical(Node *r1, Node *r2)
{
    //Your Code here
    if(r1 == NULL && r2 == NULL)
    return 1;
    if(r1 == NULL && r2 != NULL)
    return 0;
    if(r1 != NULL && r2 == NULL)
    return 0;
    
    if(r1->data != r2->data)
    return 0;
    
    return isIdentical(r1->left,r2->left) && isIdentical(r1->right,r2->right);
    
}

int main(){

    cout << "Enter the Root 1 Node " << "  : ";
    Node* root = BinaryTree();
    cout << endl << endl;
    cout << "Enter the Root 2 Node " << "  : ";
    Node* root2 = BinaryTree();
    
    cout << endl << "IS Identical : " << isIdentical(root,root2);


return 0;
}