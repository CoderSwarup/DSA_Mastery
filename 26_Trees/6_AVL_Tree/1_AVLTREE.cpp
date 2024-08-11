#include<iostream>
using namespace std;
#include <bits/stdc++.h>

class AvlNode{

    public:

    int data ,height;
    AvlNode *left ,*right;

    AvlNode(int val){
        data =val;
        height =1;
        left = right = NULL;
    }
};

int getHeight(AvlNode *root){
    if(!root) return 0;

    return root->height;
}

int getBalance(AvlNode *root){
    return getHeight(root->left) - getHeight(root->right);
}


// Right Rotation  => L L
AvlNode* rightRotation(AvlNode* root){
    AvlNode* child = root->left;
    AvlNode* childRight = child->right;

    child->right = root;
    root->left = childRight;

    // Update height
    root->height = 1+max(getHeight(root->left),getHeight(root->right));
    child->height = 1+max(getHeight(child->left),getHeight(child->right));

    return child;
}

// Left Rotation => R R
AvlNode* leftRotation(AvlNode* root){
    AvlNode* child = root->right;
    AvlNode* childLeft = child->left;

    child->left = root;
    root->right = childLeft;

    // Update height
    root->height = 1+max(getHeight(root->left),getHeight(root->right));
    child->height = 1+max(getHeight(child->left),getHeight(child->right));

    return child;

}

// insert the 
AvlNode* insert(AvlNode *root,int key){

    // root Not Exist
    if(root==NULL){
        return new AvlNode(key);
    }

    // Exist
    if(key<root->data){ // key is less than the root data
        root->left = insert(root->left,key);
    }else if(key>root->data){// key is Greate than the root data 
        root->right = insert(root->right,key);
    }else{ // Duplicate Element
        return root;
    }

    // update height
    root->height = 1 + max(getHeight(root->left),getHeight(root->right));


    //Check the balancing
    int balance = getBalance(root);


    // Left Left Case
    if(balance > 1 && key < root->left->data){
         return rightRotation(root);

    }
    // right Right Case
    else if(balance < -1 && root->right->data  < key){
        return leftRotation(root);
    }
    // Left Right case
    else if(balance > 1 && key > root->left->data){
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }
    //Right Left Case
    else if(balance < -1 && root->right->data >key){
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }
    // No Unbalnce
    else{
        return root;
    }



}

void PreOrder(AvlNode *root){
    if(!root) return;

    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}


void InOrder(AvlNode *root){
    if(!root) return;

    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}


int main(){

    AvlNode* root = NULL;
    int arr[] = {9, 5, 10, 0, 6,11, -1, 1, 2};

    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<n;i++){
        root = insert(root,arr[i]);
    }

    cout << "Preorde of the AVL TREE is " << endl;
    PreOrder(root);
    cout << endl << "InOrder of the AVL TREE is " << endl;
    InOrder(root);



return 0;
}