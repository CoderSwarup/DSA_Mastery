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

// Merge Two Binary Tree M1

void  insertNode(Node* root,vector<int> &tree){
    if(!root) return;
    
    insertNode(root->left,tree);
    tree.push_back(root->data);
    insertNode(root->right,tree);
}
void MergeTwoTree(Node *root1, Node *root2) {
    // Your code here
    vector<int>ans;
    vector<int> tree1;
    vector<int> tree2;
    
    insertNode(root1,tree1);
    insertNode(root2,tree2);
    
    
    int i=0,j=0;
    while(i<tree1.size() && j<tree2.size()){
        if(tree1[i] < tree2[j]){
            ans.push_back(tree1[i++]);
        }else{
            ans.push_back(tree2[j++]);
        }
    }
    
    
     while(i<tree1.size()){
         ans.push_back(tree1[i++]);
     }
     
     while(j<tree2.size()){
         ans.push_back(tree2[j++]);
     }



    cout << endl << "Ans is : " ;
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
}




int main(){

    cout << "Enter the Root1 Nodes " << "  : ";
    Node* root = BinaryTree();


    cout << endl << "Enter the Root2 Nodes " << "  : ";
    Node* root1 = BinaryTree();

    MergeTwoTree(root,root1);


return 0;
}