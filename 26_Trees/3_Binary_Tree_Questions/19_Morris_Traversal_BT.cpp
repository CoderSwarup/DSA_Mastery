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

vector<int> MorrisTraversalInorder(Node* root){
    // LNR

    vector<int> ans;


    while(root){

        // if Left Not Exist 
        if(!root->left){
            ans.push_back(root->data);
            root = root->right;
        }else{

            Node *curr = root->left;

            while(curr->right && curr->right != root){
                curr = curr->right;
            }

            // left Tree Not Traverse
            if(curr->right == NULL){
                curr->right = root;
                root = root->left;
            }else{
                curr->right = NULL;
                ans.push_back(root->data);
                root = root->right;
            }
        }
        
    }

    return ans;
}

vector<int> MorrisTraversalPreOrder(Node* root){
    // LNR

    vector<int> ans;


    while(root){

        // if Left Not Exist 
        if(!root->left){
            ans.push_back(root->data);
            root = root->right;
        }else{

            Node *curr = root->left;

            while(curr->right && curr->right != root){
                curr = curr->right;
            }

            // left Tree Not Traverse
            if(curr->right == NULL){
                ans.push_back(root->data);
                curr->right = root;
                root = root->left;
            }else{
                curr->right = NULL;
                root = root->right;
            }
        }
        
    }

    return ans;
}

int main(){

    cout << "Enter the Root Node " << "  : ";
    Node* root = BinaryTree();

    cout << endl << "Morris Traversal Inorder : "<< endl;


     vector<int> ans = MorrisTraversalInorder(root);

     for(int j=0;j<ans.size();j++){
          
        cout << ans[j]<< " ";
    }

    cout << endl << "Morris Traversal PreOrder : "<< endl;


      ans = MorrisTraversalPreOrder(root);

     for(int j=0;j<ans.size();j++){
        cout << ans[j]<< " ";
    }


return 0;
}

/**

OUTPUT 

Enter the Root Node   : 1
Enter The Left Child of the 1 : 2
Enter The Left Child of the 2 : -1
Enter The Right Child of the 2 : -1
Enter The Right Child of the 1 : 3
Enter The Left Child of the 3 : -1
Enter The Right Child of the 3 : -1

Morris Traversal :
2 1 3 */