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


void MinDist(Node* root,int &prev,int &ans){
    if(!root) return;


    MinDist(root->left,prev,ans);
    if(prev != INT_MIN)
    ans = min(ans,root->data-prev);

    prev = root->data;
    MinDist(root->right,prev,ans);


}

int main(){

    cout << "Enter the Root Node " << "  : ";
    Node* root = BinaryTree();

    cout << endl;

    int prev =INT_MIN;
    int ans =INT_MAX;

    MinDist(root,prev,ans);

    cout << "MinDistance Between in the Two Trees " << ans;

 



return 0;
}