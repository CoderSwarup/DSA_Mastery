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

bool parent(Node* root,int a,int b){
    if(!root) return 0;
    
    if(root->left&&root->right){
        
        if(root->left->data ==a && root->right->data ==b) return 1;
        if(root->left->data ==b && root->right->data ==a)return 1;
    }
    
    
    return parent(root->left,a,b) || parent(root->right,a,b);
}
// Returns true if the nodes with values 'a' and 'b' are cousins. Else returns false
bool isCousins(Node *root, int a, int b) {
    // add code here.
    queue<Node*> q;
    q.push(root);
    int l1 =-1 , l2=-1;
    int level =0;
    
    while(!q.empty()){
        int n = q.size();
        
        while(n--){
            Node* t = q.front();
            q.pop();
            
            
            if(t->data ==a){
                l1=level;
            }
            if(t->data ==b){
                l2 = level;
            }
            
            if(t->left) {
                q.push(t->left);
            }
            if(t->right) {
                q.push(t->right);
            }
        }
        
        level++;
        
        
        if(l1 != l2){
            return 0;
        }
        
        
        if(l1 != -1 && l2!= -1){
            break;
        }
    }
    
    return !parent(root,a,b);
}

int main(){

    cout << "Enter the Root Node " << "  : ";
    Node* root = BinaryTree();


    int c1;
    cout << endl << "Enter cousine 1 : ";
    cin >> c1;
    int c2;
    cout << endl << "Enter cousine 2 : ";
    cin >> c2;


    cout << endl << "is Cousin " << isCousins(root,c1,c2) << endl;


return 0;
}