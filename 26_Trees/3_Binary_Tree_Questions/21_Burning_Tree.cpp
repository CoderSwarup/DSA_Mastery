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


int Brun(Node* root,int &timer,int target){

    // node not exist 
    if(!root) return 0;

    // is tartget node 
    if(root->data == target) return -1;


    int Left = Brun(root->left,timer,target);
    int Right = Brun(root->right,timer,target);

    // check the Which side is brun

    // brun from left 
    if(Left < 0){
        timer = max(timer,abs(Left)+Right);
        return Left -1;
    }

    // brun from the righ t
    if(Right < 0){
        timer = max(timer,Left+abs(Right));
        return Right -1;
    }


    // Return Height 
    return 1+max(Left,Right);
}

// find the Brun Node 
void find(Node* root,int target,Node* &BrunNode){
    if(!root) return;

    if(root->data == target){
        BrunNode = root;
        return;
    }

    find(root->left,target,BrunNode);
    find(root->right,target,BrunNode);

}


// find the Height of the Bru node

int Height(Node *root){
    if(!root) return 0;

    return 1+max(Height(root->left),Height(root->right));
}

int main(){

    cout << "Enter the Root Node " << "  : ";
    Node* root = BinaryTree();

    cout << endl;

    cout << "Enter the Target Node : " ;
    int target;
    cin >> target;


    cout << endl << "Time Taken By to burn the Tree " << endl;
    int timer =0;

    Brun(root,timer,target);

    // height of the Target Node
    Node* BrunNode = NULL;

    find(root,target,BrunNode);

    int height = Height(BrunNode) -1;


    int ans = max(timer,height);

    cout << ans;




return 0;
}
