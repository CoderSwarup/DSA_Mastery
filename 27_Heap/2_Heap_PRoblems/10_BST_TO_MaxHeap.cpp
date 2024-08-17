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



void Inorder(vector<int> &ans,Node *root){
    if(!root) return;
    
    Inorder(ans,root->left);
    ans.push_back(root->data);
    Inorder(ans,root->right);
}


 void PostOrder(vector<int> &ans,Node *root,int &index){
    if(!root) return;
    
    PostOrder(ans,root->left,index);
    PostOrder(ans,root->right,index);
    root->data = ans[index];
    index++;
    
}

void PrintPostOrder(Node *root){
    if(!root) return;
    
    PrintPostOrder(root->left);
    PrintPostOrder(root->right);
    cout<< root->data << " ";
    
    
}
void convertToMaxHeapUtil(Node* root)
{
    // Your code goes here
    vector<int>ans;
    Inorder(ans,root);
    int index =0;
    PostOrder(ans,root,index);
}  

int main(){

    cout << "Enter the Root Node " << "  : ";
    Node* root = BinaryTree();

    convertToMaxHeapUtil(root);

    cout <<  endl << "Max Heap is " <<endl;
    PrintPostOrder(root);

return 0;
}



/*
Input :
                 4
               /   \
              2     6
            /  \   /  \
           1   3  5    7  

Output : 1 2 3 4 5 6 7 
Exaplanation :
               7
             /   \
            3     6
          /   \  /   \
         1    2 4     5
The given BST has been transformed into a
Max Heap and it's postorder traversal is
1 2 3 4 5 6 7.
*/