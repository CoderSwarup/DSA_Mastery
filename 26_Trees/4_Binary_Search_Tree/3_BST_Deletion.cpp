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



Node* BSTInsert(Node* root,int target){
    if(root == NULL) {
        Node* temp =new Node(target);
        return temp;
    }

    if(target < root->data){
        root->left = BSTInsert(root->left,target);
    }else{
        root->right = BSTInsert(root->right,target);

    }


    return root;
}


void inOrder(Node* root){
    if(!root) return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);


}

Node* BSTDelete(Node* root,int target){
    // target Not Present 
    if(!root) return NULL;

    // is Target smaller than the root->data
    if(target<root->data){
        root->left = BSTDelete(root->left,target);
        return root;
    }
    
    // target is Greate Than root->data
    else if(target>root->data){
        root->right = BSTDelete(root->right,target);
        return root;
    }


    else{

        // Leaf Node
        if(!root->left && !root->right){
            delete root;
            return NULL;
        }
        // Left child exist
        else if(!root->right){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Right child exist
        else if(!root->left){
            Node* temp = root->right;
            delete root;
            return temp;
            
        }
        // Bioth Child Exist 
        else{

            // Find the Greatest Element From the Left
            Node *child = root->left;
            Node *parent = root;

            // Right Most  Node
            while(child->right){
                parent = child;
                child = child->right;
            }


            // root != parent 
            if(root != parent){
                parent->right = child->left;
                child->left = root->left;
                child->right = root->right;
                delete root;
                return child;
            }else{
                child->right = root->right;
                delete root;
                return child;
            }
        }
    }
}



int main(){

    vector<int> arr = {6,3,17,5,11,18,2,1,20,14};

    Node* root = NULL;
    // Create a BSTInsert
    for(int i=0;i<arr.size();i++)
    root = BSTInsert(root,arr[i]);

    cout << endl << "Enter The Target Node Vlaue To Delete the Node " ;
    int target;
    cin >> target;

    root = BSTDelete(root,target);
    cout << endl << "New BST Tree is : ";
    inOrder(root);


return 0;
}