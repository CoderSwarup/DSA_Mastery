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

vector<int> leftView(Node *root)
{
   vector<int> ans;
    if(!root) return ans;
   // Your code here
   queue<Node*>q;
   q.push(root);
   
   while(!q.empty()){
       int n = q.size();
       Node* t = q.front();
       ans.push_back(t->data);
       
       while(n--){
           Node* t = q.front();
           q.pop();
           
           if(t->left){
               q.push(t->left);
           }
           
           
           if(t->right){
               q.push(t->right);
           }
           
       }
   }
   
   return ans;
}


// using recursion 

void LVRecursion(Node* r,int level,vector<int> &ans){
    if(!r) return;

    if(ans.size() == level){
        ans.push_back(r->data);
    }

    LVRecursion(r->left,level+1,ans);
    LVRecursion(r->right,level+1,ans);

}
int main(){

    cout << "Enter the Root Node " << "  : ";
    Node* root = BinaryTree();

    cout << endl << "Left View Of Binary Tree " << endl;
    // using queue
    // vector<int> ans = leftView(root);

    // using recursion
    int level =0;
    vector<int> ans;
    LVRecursion(root,level,ans);

    for(int i=0;i<ans.size();i++)
    cout << ans[i] << " ";



return 0;
}