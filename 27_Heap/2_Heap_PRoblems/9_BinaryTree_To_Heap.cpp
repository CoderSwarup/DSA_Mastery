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


int count(Node *root){
        if(!root) return 0;
        
        return 1 + count(root->left) + count(root->right);
}
    
bool CBT(Node *root,int index,int totalNodes){
        if(!root) return 1;
        
        
        if(index>=totalNodes) return 0;
        
        return CBT(root->left,2*index+1,totalNodes) && CBT(root->right,2*index+2,totalNodes);
        
}
    
bool MaxHeap(Node *root){
    // root null
    //left child exist 
    //right child exist
    //Both Child Exist
    
    if(root->left){
        if(root->data < root->left->data){
            return 0;
        }
        
         if(!MaxHeap(root->left)) return 0;
    }
    
    if(root->right){
        if(root->data < root->right->data){
            return 0;
        }
        
         return MaxHeap(root->right);
    }
    
     return 1;
}
bool isHeap(Node* tree) {
    // code here
    
    //count nodes in tree
    int n =count(tree);
    
    // check is CBT
    
    bool ans = CBT(tree,0,n);
    
    if(ans ==0) return 0;
    
    // parent >= child
    
   return   MaxHeap(tree);
}

int main(){

    
    cout << "Enter the Root Node " << "  : ";
    Node* root = BinaryTree();

    cout << endl;

    cout << "Give tree is Heap " <<endl;
    cout << isHeap(root) << endl;

return 0;
}