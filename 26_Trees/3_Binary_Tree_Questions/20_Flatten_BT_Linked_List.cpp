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

void Flatten(Node* root){

    while(root){

        if(!root->left){
            root = root->right;
        }else{
            Node* curr = root->left;

            while(curr->right){
                curr = curr->right;
            }

            curr->right = root->right;
            root->right = root->left;
            root->left = NULL;
            root= root->right;
        }
    }

}

int main(){

    cout << "Enter the Root Node " << "  : ";
    Node* root = BinaryTree();

     Flatten(root);


    cout << endl << "Flatten Tree " << endl;

    while(root){
        cout << root->data << " ";
        root = root->right;
    }




return 0;
}

/**


2 1 3 */