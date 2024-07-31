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

vector<int> PreOrder(Node* root)
{
    //code here
    stack<Node*> s;
    s.push(root);
    vector<int> ans;
    
    while(!s.empty()){
        Node *temp = s.top();
        s.pop();
        
        ans.push_back(temp->data);
        
        if(temp->right){
            s.push(temp->right);
        }
        
        if(temp->left){
            s.push(temp->left);
        }
    }
    
    return ans;
}

// in-order => L N R
vector<int> InOrder(Node* root)
{
    //code here
    stack<Node*>s;
    stack<bool> visited;
    
    s.push(root);
    visited.push(0);
    
    vector<int> ans;
    
    
    while(!s.empty()){
        
        Node* temp = s.top();
        s.pop();
        bool flag = visited.top();
        visited.pop();
        
        if(!flag){
            //push right child
            if(temp->right){
                s.push(temp->right);
                visited.push(0);
            }
            
            // push the Node 
            s.push(temp);
            visited.push(1);
            
            // push left side
            if(temp->left){
                s.push(temp->left);
                visited.push(0);
            }
            
        }else{
            ans.push_back(temp->data);
        }
    }
    
    return ans;
}


// post-order => L R N
vector<int> PostOrder(Node* node) {
    // code here
    // L R N ==>  N R L
    stack<Node*> s;
    s.push(node);
    vector<int> ans;
    
    while(!s.empty()){
        Node *temp = s.top();
        s.pop();
        
        ans.push_back(temp->data);
        
        if(temp->left){
            s.push(temp->left);
        }
        
        if(temp->right){
            s.push(temp->right);
        }
        
        
    }
    reverse(ans.begin(),ans.end());
    return ans;
}



void printArray(vector<int> arr){
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
        }
}



int main(){

    cout << "Enter the Root Node " << "  : ";
    Node* root = BinaryTree();


    cout << "Traversing the TREE" << endl << endl;

    vector<int> ans;

    cout << "Pre-Order Traversal" << endl;
    ans = PreOrder(root);
    printArray(ans);


    cout << endl;

    cout << "In-Order Traversal" << endl;
    ans = InOrder(root);
    printArray(ans);

    cout << endl;

    cout << "Post-Order Traversal" << endl;
    ans = PostOrder(root);
    printArray(ans);




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