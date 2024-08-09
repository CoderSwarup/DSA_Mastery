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


void correctBST(  Node* root )
{
        // add code here.
      Node *curr =NULL;
      Node *first =NULL , *second = NULL;
      Node *last = NULL , *present = NULL;
        
        while(root){
            //left not Exist
            if(!root->left){
                last = present;
                present = root;
                if(last && last->data > present->data){
                    if(!first){ 
                        first =last;
                    
                    };
                    second = present;
                }
                root = root->right;
            }
            else{ // Left Exist
                
                curr = root->left;
                while(curr->right && curr->right !=root){
                    curr =curr->right;
                }
                // Left subtree Not Traverse
                if(!curr->right){
                    curr->right = root;
                    root= root->left;
                }
                // Left subtree Already Traverse 
                else{
                    
                    curr->right = NULL;
                    last = present;
                    present = root;
                    if(last && last->data > present->data){
                        if(!first) {
                            first =last;
                            
                        };
                        second = present;
                    }
                    root = root->right;
                }
            }
        }
        
        
        // swap
        int num = first->data;
        first->data  = second->data;
        second->data = num;
}

int main(){

    cout << "Enter the Root Nodes " << "  : ";
    Node* root = BinaryTree();


    correctBST(root);

return 0;
}