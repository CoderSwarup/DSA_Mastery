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


// Tree Traversal
// TC O(N)
// SC O(H) / W = O(N)

// pre-order => N L R

void PreOrder(Node* root){
    if(root == NULL) return;

    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

// in-order => L N R
void InOrder(Node* root){
    if(root == NULL) return;

    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}


// post-order => L R N
void PostOrder(Node* root){
    if(root == NULL) return;

    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}




int main(){

    cout << "Enter the Root Node " << "  : ";
    Node* root = BinaryTree();


    cout << "Traversing the TREE" << endl << endl;

    cout << "Pre-Order Traversal" << endl;
    PreOrder(root);

    cout << endl;

    cout << "In-Order Traversal" << endl;
    InOrder(root);

    cout << endl;

    cout << "Post-Order Traversal" << endl;
    PostOrder(root);



return 0;
}

/**
 * OUTPUT 
 */


/**

Enter the Root Node   : 1
Enter The Left Child of the 1 : 2
Enter The Left Child of the 2 : 3
Enter The Left Child of the 3 : 4
Enter The Left Child of the 4 : -1
Enter The Right Child of the 4 : -1
Enter The Right Child of the 3 : 5
Enter The Left Child of the 5 : -1
Enter The Right Child of the 5 : -1
Enter The Right Child of the 2 : 6
Enter The Left Child of the 6 : -1
Enter The Right Child of the 6 : -1
Enter The Right Child of the 1 : 7
Enter The Left Child of the 7 : -1
Enter The Right Child of the 7 : 8
Enter The Left Child of the 8 : 9
Enter The Left Child of the 9 : -1
Enter The Right Child of the 9 : -1
Enter The Right Child of the 8 : 10
Enter The Left Child of the 10 : -1
Enter The Right Child of the 10 : -1
Traversing the TREE

Pre-Order Traversal
1 2 3 4 5 6 7 8 9 10
In-Order Traversal
4 3 5 2 6 1 7 9 8 10
Post-Order Traversal
4 5 3 6 2 9 10 8 7 1

 */