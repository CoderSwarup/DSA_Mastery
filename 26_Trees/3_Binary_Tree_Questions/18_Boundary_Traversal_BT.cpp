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


void LeftSub(Node *root,vector<int> &ans){

    if(!root || (!root->left && !root->right)) return;
    ans.push_back(root->data);

    if(root->left)
    LeftSub(root->left,ans);
    else
    LeftSub(root->right,ans);

}

void Leaf(Node *root,vector<int> &ans){
    if(!root) return;

    //Leaf Node
    if(!root->left && !root->right){
        ans.push_back(root->data);
        return;
    }

    //Left 
    Leaf(root->left,ans);
    //Right
    Leaf(root->right,ans);

}


void RightSub(Node *root,vector<int> &ans){

    if(!root || (!root->left && !root->right)) return;


    if(root->right)
    LeftSub(root->right,ans);
    else
    LeftSub(root->left,ans);


    //print
    ans.push_back(root->data);
}

vector<int> Boundary(Node* root){


    vector<int> ans;

    // root Element 
    ans.push_back(root->data);

    

    //Left boundary element to deal do except leaf Node
    LeftSub(root->left,ans);

    //Leaf Node insert 
    if(root->left || root->right) // cond if the only Single root present 
    Leaf(root,ans);

    //Right boundary element to deal do except leaf Node
    RightSub(root->right,ans);


    return ans;



}

int main(){

    cout << "Enter the Root Node " << "  : ";
    Node* root = BinaryTree();

    cout << endl << "Boundary Trversal "<<endl;

    vector<int> ans = Boundary(root);

     for(int j=0;j<ans.size();j++){
          
        cout << ans[j]<< " ";
    }




return 0;
}


/**
OUTPUT 


Enter the Root Node   : 1
Enter The Left Child of the 1 : 2
Enter The Left Child of the 2 : 4
Enter The Left Child of the 4 : -1
Enter The Right Child of the 4 : -1
Enter The Right Child of the 2 : 5
Enter The Left Child of the 5 : 7
Enter The Left Child of the 7 : -1
Enter The Right Child of the 7 : -1
Enter The Right Child of the 5 : 8
Enter The Left Child of the 8 : -1
Enter The Right Child of the 8 : -1
Enter The Right Child of the 1 : 3
Enter The Left Child of the 3 : -1
Enter The Right Child of the 3 : 6
Enter The Left Child of the 6 : 9
Enter The Left Child of the 9 : -1
Enter The Right Child of the 9 : -1
Enter The Right Child of the 6 : 10
Enter The Left Child of the 10 : -1
Enter The Right Child of the 10 : -1

Boundary Trversal
1 2 4 7 8 9 10 6 3
 */

/**
For the Sigle root

Enter the Root Node   : 1
Enter The Left Child of the 1 : -1
Enter The Right Child of the 1 : -1

Boundary Trversal
1
 */