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


bool BSTSearch(Node* root,int target){
    if(!root) return 0;

    if(root->data == target )return 1;

    if(target<root->data){
        return BSTSearch(root->left,target);
    }else{
        return BSTSearch(root->right,target);

    }
}


int main(){

    vector<int> arr = {6,3,17,5,11,18,2,1,20,14};

    Node* root = NULL;
    // Create a BSTInsert
    for(int i=0;i<arr.size();i++)
    root = BSTInsert(root,arr[i]);

    cout << endl << "Enter The Target " ;
    int target;
    cin >> target;

    cout << endl << "Is Target Present : " << BSTSearch(root,target);



return 0;
}