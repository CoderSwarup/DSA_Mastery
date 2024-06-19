#include<iostream>
using namespace std;
#include <bits/stdc++.h>

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
    Node *Tail = NULL;
    int arr[4] = {1,2,3,4};

       //push at the End
       for(int i=0;i<4;i++){
        if(Head == NULL){
            Head = new Node(arr[i]);
            Tail = Head;
        }else{
            Tail->next = new Node(arr[i]);
            Tail = Tail->next;
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