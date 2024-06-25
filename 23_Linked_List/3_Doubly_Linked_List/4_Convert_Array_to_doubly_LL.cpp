#include<iostream>
using namespace std;
#include <bits/stdc++.h>


class Node {
    public:
    int data;
    Node *prev , *next;

    Node(int val){
        data = val;
        prev = NULL;
        next = NULL;
    }
};

int main(){

    Node *Head = NULL;
    vector<int>arr = {1,2,3,4,5};

    Node* Tail  = Head;

    for(int i=0;i<arr.size();i++){
        if(Head == NULL){
            Head = new Node(arr[i]);
            Tail = Head;
        }else{
            Node *temp = new Node(arr[i]);
            Tail->next = temp;
            Tail = temp;
        }
    }

    
   
    // Print the data of the nodes
    Node *temp = Head;
    while(temp!= NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}