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

vector<int> findSpiral(Node *root)
{
    //Your code here
    stack<Node*> s1; // R to L
    stack<Node*> s2; // L to R
    
    vector<int> ans;
    
    s1.push(root);
    
    while(!s1.empty() || !s2.empty()){
        
        if(!s1.empty()){
            while(!s1.empty()){
                Node* t = s1.top();
                s1.pop();
            
                ans.push_back(t->data);
            
                // push the Element in s2 (R to L)
                if(t->right) s2.push(t->right);
            
                if(t->left) s2.push(t->left);
            }
        }else{
            while(!s2.empty()){
                Node* t = s2.top();
                s2.pop();
                
                ans.push_back(t->data);
                
                // push the Element in s1 (L to R)
                if(t->left) s1.push(t->left);
                if(t->right) s1.push(t->right);
                
            }
        }
    }
    
    
    return ans;
}

int main(){

    cout << "Enter the Root Node " << "  : ";
    Node* root = BinaryTree();

    cout << endl << "ans : " ;

    vector<int> ans = findSpiral(root);


    for(int i=0;i<ans.size();i++)
    cout << ans[i] << " ";


return 0;
}