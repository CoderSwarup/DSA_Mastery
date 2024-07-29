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


int height(Node* root,bool &valid){
        if(!root) return 0;
        
        int L = height(root->left,valid);
        if(valid){
            int R = height(root->right,valid);
            if(abs(L-R)>1){
                valid = 0;
            }
            
            return 1+max(L,R);
        }
        
        return -1;
    }
bool isBalanced(Node *root)
{
    //  Your Code here
    bool valid =1;
    height(root,valid);
    return valid;
}

// Balance tree = 
//      -1 <= height(L) -height(R) <= 1
//              (-1 , 0 , 1)

int main(){

    cout << "Enter the Root Node " << "  : ";
    Node* root = BinaryTree();

    cout << endl;

    cout << "Is Tree Balance : " << isBalanced(root);


return 0;
}