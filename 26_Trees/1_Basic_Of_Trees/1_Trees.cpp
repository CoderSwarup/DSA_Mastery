#include<iostream>
using namespace std;
#include <bits/stdc++.h>

//Create a Node
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



int main(){

    queue<Node*>q;
    int x , first , sec;
    cout << "Enter the Root Node Data : " ; 
    cin >>  x;

    Node* root = new Node(x);
    q.push(root);

    while(!q.empty()){
        Node* t = q.front();
        q.pop();
        cout << "Enter the Left Child of " << t->data << " : " ;
        cin >> first;
        if(first != -1){
            Node* left = new Node(first);
            t->left = left;
            q.push(left);
        }
        cout << "Enter the Right Child of " << t->data << " : " ;
        cin >> sec;
        if(sec != -1){
            Node* right = new Node(sec);
            t->right = right;
            q.push(right);
        }
    }


return 0;
}