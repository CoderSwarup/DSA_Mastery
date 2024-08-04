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


int MaxPathBetweenTwoSpecialNodes(Node *root,int &MAX_SUM){
    if(!root) return 0;

    //Leaf Node
    if(!root->left && !root->right) return root->data;


    int Left = MaxPathBetweenTwoSpecialNodes(root->left,MAX_SUM);
    int Right = MaxPathBetweenTwoSpecialNodes(root->right,MAX_SUM);

    // left and right both exist
    if(root->left && root->right){
        MAX_SUM = max(MAX_SUM,root->data + Left + Right);
        return root->data + max(Left,Right);
    }


    // if only left exist
    if(root->left){
        return root->data + Left;
    }

    // if only right exist
    if(root->right){
        return root->data + Right;
    }

}

int main(){

    cout << "Enter the Root Node " << "  : ";
    Node* root = BinaryTree();



    cout << endl << "Maximum Path Between Two Special Node is  " << endl;
    int MAX_SUM = INT_MIN;
    int val = MaxPathBetweenTwoSpecialNodes(root,MAX_SUM);

    // Edge case Root Node is Special Node
    if(!root->left || !root->right){
        cout << max(MAX_SUM,val);
    }else{
        cout << MAX_SUM;
    }





return 0;
}
