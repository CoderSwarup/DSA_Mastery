#include<iostream>
using namespace std;
#include <bits/stdc++.h>

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }

};


void CheckIsPalindromeUsingExtraSpace(Node* Head){
    vector<int> dataArr;

    Node* temp = Head;

    while(temp){
        dataArr.push_back(temp->data);
        temp = temp->next;
    }

    int start= 0;
    int end = dataArr.size()-1;
    while(start<end){
        if(dataArr[start] != dataArr[end]){
            cout<< endl <<"Not a Palindrome"<<endl;
            return;
        }
        start++;
        end--;
    }

 
    cout<< endl <<"is a Palindrome"<<endl;
    
   
}


void CheckPalindromWithoutUsingExtraSpace(Node *head){
    Node *slow = head, *fast = head;
    stack<int> st;


    while(fast && fast->next){
        st.push(slow->data);
        slow = slow->next;
        fast = fast->next->next;
    }


    if(fast){
        slow = slow->next;
    }
    while(slow){
        if(slow->data != st.top()){
            cout<< endl <<"Not a Palindrome"<<endl;
            return;
        }
        st.pop();
        slow = slow->next;
    }
    cout<< endl <<"is a Palindrome"<<endl;
}


void CheckPalindromWithoutUsingExtraSpaceM2(Node *head){

     if (head == NULL )
            return 0;

        if(head->next == NULL){
            return 1;
        }
    cout << "DGcfgd" << endl;
   Node *temp = head;
   int count = 0;
   while(temp){
    count++;
    temp = temp->next;
   }

  
    int mid = count/2;
//    cout<<mid << endl;

    Node *next = head;
    Node *prev = NULL;

    while(mid--){
        prev = next;
        next = next->next;

    }
    prev->next = NULL;

    prev = NULL;
    Node *curr = next;

    //Reverse a LL
    while(curr){
        Node *t = curr->next;
        curr->next = prev;
        prev = curr;
        curr = t;
        
    }



    // now check 
    Node *t1 = head;
    Node *t2 = prev;
    while(t1 && t2){
        if(t1->data != t2->data){
            cout << "NOT A PALINDROM"<<endl;
            return ;
        }
        t1 = t1->next;
        t2 = t2->next;
    }

    cout << "IS A PALINDROM"<<endl;


}
int main(){

    Node *Head = new Node(1);
    Head->next = new Node(2);
    Head->next->next = new Node(3);
    Node *N = new Node(3);
    Head->next->next->next  = N;
    Node *NN = new Node(2);
   Head->next->next  = NN;
    Node *NNN = new Node(1);
     NN->next  = NNN;
     
    // CheckIsPalindromeUsingExtraSpace(Head);
    // CheckPalindromWithoutUsingExtraSpace(Head);
    CheckPalindromWithoutUsingExtraSpaceM2(Head);

    Node *t = Head;
    while(t!=NULL){
        cout << t->data << " ";
        t = t->next;

    }


    
   

return 0;
}