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


// using inorder reverse R N L
void KLargest(Node* root,int &ele,int &k){
    if(!root) return;

    KLargest(root->right,ele,k);

    k--;
    if(k==0){
        ele = root->data;
    }

    if(k<=0) return;

    KLargest(root->left,ele,k);


}


int main(){

    cout << "Enter the Root Node " << "  : ";
    Node* root = BinaryTree();

    cout << endl;

    int k;
    cout << "Enter the K ";
    cin >> k;

    int ele = 0;

    KLargest(root,ele,k);


    cout << endl << "k Largest Element is " << ele;

    

 



return 0;
}