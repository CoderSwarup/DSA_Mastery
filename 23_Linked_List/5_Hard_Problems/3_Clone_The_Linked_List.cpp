#include <iostream>
using namespace std;
#include <unordered_map>

class Node {
public:
    int data;
    Node* next;
    Node* arb;
    Node(int val) : data(val), next(nullptr), arb(nullptr) {}
};

Node* find(Node* curr1, Node* curr2, Node* point) {
    if (point == NULL) return NULL;
    
    while (curr1 != point) {
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    
    return curr2;
}

// TC O(N2)
Node* copyList(Node* head) {
    if (!head) return nullptr;

    // Step 1: Create a copy of the list without handling random pointers
    Node* headCopy = new Node(0);  // Temporary node
    Node* tailCopy = headCopy;
    
    Node* temp = head;
    while (temp) {
        tailCopy->next = new Node(temp->data);  // Create new nodes
        tailCopy = tailCopy->next;
        temp = temp->next;
    }
    
    tailCopy = headCopy;
    headCopy = headCopy->next;
    delete tailCopy;  // Delete temporary node
    
    // Step 2: Assign random pointers for the copied nodes
    tailCopy = headCopy;
    temp = head;
    
    while (temp) {
        tailCopy->arb = find(head, headCopy, temp->arb);
        tailCopy = tailCopy->next;
        temp = temp->next;
    }
    
    return headCopy;
}


// TC O(N) SC(n)
// usnig the hash map

Node *copyListBetter(Node *head)
{
    //Write your code here
    Node *headCopy = new Node(0);
    Node *tailCopy = headCopy;
    unordered_map<Node *,Node *> address;
    Node *temp = head;
    while(temp){
       tailCopy->next = new Node(temp->data);
       address[temp] = tailCopy->next;
        tailCopy = tailCopy->next;
        temp = temp->next;
    }
    
            
    tailCopy = headCopy;
    headCopy = headCopy->next;
    delete tailCopy;
    
    // 
    tailCopy = headCopy;
    temp = head;
    
    while(temp ){
        tailCopy->arb  = address[temp->arb];
        tailCopy = tailCopy->next;
        temp = temp->next;
    }
    
    return headCopy;
}



//Optimal
//SC O(1)
// TC O(n)


Node *copyListOptimal(Node *head)
{
    //Write your code here
    Node *headCopy = new Node(0);
    Node *tailCopy = headCopy;
    unordered_map<Node *,Node *> address;
    Node *temp = head;
    while(temp){
       tailCopy->next = new Node(temp->data);
       address[temp] = tailCopy->next;
        tailCopy = tailCopy->next;
        temp = temp->next;
    }
    
            
    tailCopy = headCopy;
    headCopy = headCopy->next;
    delete tailCopy;
    
    Node *curr1 = head;
    Node *curr2 = headCopy;
    
    while(curr1){
        Node *f1 = curr1->next;
        Node *f2 = curr2->next;
        curr1->next = curr2;
        curr2->next = f1;
        curr1= f1;
        curr2 = f2;
    }
    
    
    
    // now handle the arb pointer
    Node*  curr = head;
    while(curr){
        Node *f = curr->next;
        if(curr->arb)
        f->arb = curr->arb->next;
        curr = f->next;
    }
    
    
    // seperate the LL
    
    curr = head;
    while(curr->next){
        Node *f = curr->next;
        curr->next = f->next;
        curr = f;
    }
    
    return headCopy;
    
}



void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << "Node: " << temp->data;
        if (temp->arb) {
            cout << ", Random points to: " << temp->arb->data << endl;
        } else {
            cout << ", Random points to: NULL" << endl;
        }
        temp = temp->next;
    }
}

int main() {
    // Create original list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    
    // Set random pointers
    head->arb = head->next;                // 1 -> 2
    head->next->arb = head->next->next->next; // 2 -> 4
    head->next->next->arb = head;          // 3 -> 1
    head->next->next->next->arb = head->next->next; // 4 -> 3
    
    cout << "Original list:" << endl;
    printList(head);
    
    // Create a copy of the list
    // Node* copiedList = copyList(head);
    // Node* copiedList = copyListBetter(head);
    Node* copiedList = copyListOptimal(head);
    
    cout << "Copied list:" << endl;
    printList(copiedList);
    
    return 0;
}
