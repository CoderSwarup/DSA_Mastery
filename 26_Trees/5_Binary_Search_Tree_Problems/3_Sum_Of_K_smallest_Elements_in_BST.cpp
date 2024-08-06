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


void KSum(Node* root,int &sum,int &k){
    if(!root) return;


    KSum(root->left,sum,k);
    k--;

    if(k>=0)
    sum += root->data;


    if(k<=0) return;

    KSum(root->right,sum,k);
}


int main(){

    cout << "Enter the Root Node " << "  : ";
    Node* root = BinaryTree();

    cout << endl;

    int k;
    cout << "Enter the K ";
    cin >> k;

    int sum = 0;

    KSum(root,sum,k);


    cout << endl << "k  Smallest sum is " << sum;

    

 



return 0;
}