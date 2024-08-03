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


void findLRMost(Node* root,int pos ,int &l,int &r){
    if(!root) return;


    l = min(l,pos);
    r = max(r,pos);

    findLRMost(root->left,pos-1,l,r);
    findLRMost(root->right,pos+1,l,r);
}

vector<int> Vertical(Node* root){
    int l =0 , r =0;
    findLRMost(root,0,l,r);

    vector<vector<int>> positive(r+1);
    vector<vector<int>> negative(abs(l)+1);

    queue<Node*> q;
    queue<int> index;

    q.push(root);
    index.push(0);

    while(!q.empty()){
        Node* t = q.front();
        q.pop();
        int pos = index.front();
        index.pop();

        if(pos >=0){
            positive[pos].push_back(t->data);
        }else{

            negative[abs(pos)].push_back(t->data);
        }

        if(t->left){
            q.push(t->left);
            index.push(pos-1);
        }
        if(t->right){
            q.push(t->right);
            index.push(pos+1);
        }
    }


    vector<int> ans;

    for(int i=negative.size() -1;i>=1;i--){
        for(int j=0;j<negative[i].size();j++){
            ans.push_back(negative[i][j]);
        }
    }

     for(int i=0;i<positive.size();i++){
        for(int j=0;j<positive[i].size();j++){
            ans.push_back(positive[i][j]);
        }
    }

    return ans;
}

int main(){

    cout << "Enter the Root Node " << "  : ";
    Node* root = BinaryTree();

    cout << endl << "Vertical View is " << endl;

    vector<int> ans = Vertical(root);

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
Enter The Left Child of the 5 : -1
Enter The Right Child of the 5 : -1
Enter The Right Child of the 1 : 3
Enter The Left Child of the 3 : 6
Enter The Left Child of the 6 : -1
Enter The Right Child of the 6 : 8
Enter The Left Child of the 8 : -1
Enter The Right Child of the 8 : -1
Enter The Right Child of the 3 : 7
Enter The Left Child of the 7 : -1
Enter The Right Child of the 7 : 9
Enter The Left Child of the 9 : -1
Enter The Right Child of the 9 : -1

Vertical View is
4 2 1 5 6 3 8 7 9
 */