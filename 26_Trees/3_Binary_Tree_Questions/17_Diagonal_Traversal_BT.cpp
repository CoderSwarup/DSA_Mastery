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

void findLMost(Node* root,int pos ,int &l){
    if(!root) return;


    l = max(l,pos);

    findLMost(root->left,pos+1,l);
    findLMost(root->right,pos,l);
}

// pre order Traversal
void findDiagonal(Node* root,int pos,vector<vector<int>> &ans){
    if(!root) return;

    ans[pos].push_back(root->data);
    findDiagonal(root->left,pos+1,ans);
    findDiagonal(root->right,pos,ans);

}

vector<int> Diagonal(Node* root){
    int l=0;
    findLMost(root,0,l);

    vector<vector<int>>ans(l+1);

    findDiagonal(root,0,ans);

    vector<int> temp;

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            temp.push_back(ans[i][j]);
        }
    }

    return temp;

}

int main(){

    cout << "Enter the Root Node " << "  : ";
    Node* root = BinaryTree();

    cout << endl << "Diagonal Trversal "<<endl;

    vector<int> ans = Diagonal(root);

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
Enter The Left Child of the 4 : 7
Enter The Left Child of the 7 : -1
Enter The Right Child of the 7 : 11
Enter The Left Child of the 11 : -1
Enter The Right Child of the 11 : -1
Enter The Right Child of the 4 : 8
Enter The Left Child of the 8 : -1
Enter The Right Child of the 8 : -1
Enter The Right Child of the 2 : 5
Enter The Left Child of the 5 : -1
Enter The Right Child of the 5 : -1
Enter The Right Child of the 1 : 3
Enter The Left Child of the 3 : -1
Enter The Right Child of the 3 : 6
Enter The Left Child of the 6 : 9
Enter The Left Child of the 9 : -1
Enter The Right Child of the 9 : -1
Enter The Right Child of the 6 : 10
Enter The Left Child of the 10 : -1
Enter The Right Child of the 10 : -1

Diagonal Trversal
1 3 6 10 2 5 9 4 8 7 11
 */