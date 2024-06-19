#include<iostream>
using namespace std;
#include <bits/stdc++.h>

class Node{
    public:
    int data;
    Node* next;

    Node(int value ){
        data = value;
        next = NULL;
    }
};

int main(){

    Node *Head = NULL;

    int arr[4] = {1,2,3,4};

    //push at the Begin
    for(int i=0;i<4;i++){
        // if head is Null
        if(Head==NULL){

            Head = new Node(arr[i]);
        }else{
            Node *temp = new Node(arr[i]);
            temp->next = Head;
            Head = temp;
        }
    }
    //Traverse
    Node *temp = Head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }


return 0;
}