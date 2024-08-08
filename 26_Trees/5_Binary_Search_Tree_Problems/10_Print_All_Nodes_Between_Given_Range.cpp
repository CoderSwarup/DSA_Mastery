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


void printInorder(Node *root){
    if(!root) return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);

        
}


void Find(Node* root, int low, int high,vector<int> &ans){
     if(!root) return;
     
      
     if(root->data>low && root->data>high){
         Find(root->left,low,high,ans);
     }else if(root->data<low && root->data<high){
         Find(root->right,low,high,ans);
     }else{
            Find(root->left,low,high,ans);
            ans.push_back(root->data);
            Find(root->right,low,high,ans);
     }
}

int main(){
    cout << "Enter the Root Node " << "  : ";
    Node* root = BinaryTree();

    cout << endl << "Your Tree : ";
    printInorder(root);


    int Low ,high;
    cout << endl << "Enter The Low Value ";
    cin >> Low;
    cout << endl << "Enter The high Value ";
    cin >> high;


    vector<int> ans;
    Find(root,Low,high,ans);


    cout << endl << "Within Range Vlaues are "<< endl;
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }

return 0;
}


/**
OUTPUT

Enter the Root Node   : 17
Enter The Left Child of the 17 : 4
Enter The Left Child of the 4 : 2
Enter The Left Child of the 2 : -1
Enter The Right Child of the 2 : -1
Enter The Right Child of the 4 : 9
Enter The Left Child of the 9 : -1
Enter The Right Child of the 9 : -1
Enter The Right Child of the 17 : 18
Enter The Left Child of the 18 : -1
Enter The Right Child of the 18 : -1

Your Tree : 2 4 9 17 18
Enter The Low Value 4

Enter The high Value 22

Within Range Vlaues are
4 9 17 18


 */