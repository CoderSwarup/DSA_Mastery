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


vector <int> findCommon(Node *root1, Node *root2){
     //Your code here
     vector<int>ans;
     stack<Node*>s1,s2;
     
     while(root1){
         s1.push(root1);
         root1= root1->left;
     }
     
        while(root2){
         s2.push(root2);
         root2= root2->left;
     }
     
     
     while(!s1.empty() && !s2.empty()){
         // top Elements Equal
         if(s1.top()->data == s2.top()->data){
             ans.push_back(s1.top()->data);
             
             root1 = s1.top()->right;
             s1.pop();
             
             root2 = s2.top()->right;
             s2.pop();
             
         }
         // s1 top > s2 top
         else if(s1.top()->data >  s2.top()->data){
             root2 = s2.top()->right;
             s2.pop();
         }
         
         // s1 top < s2 top
         else{
             root1 = s1.top()->right;
             s1.pop();
         }
         
        while(root1){
            s1.push(root1);
            root1= root1->left;
        }
     
        while(root2){
            s2.push(root2);
            root2= root2->left;
        }
     }
     
     
     return ans;
}

int main(){


    cout << "Enter the Root1 Nodes " << "  : ";
    Node* root1 = BinaryTree();

    cout << endl;

    cout << "Enter the Root1 Nodes2 " << "  : ";
    Node* root2 = BinaryTree();

    vector<int> ans  = findCommon(root1,root2);

    cout << endl << "All Common Nodes Between Two Trees "<< endl;
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }



return 0;
}