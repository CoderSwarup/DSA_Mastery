#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* bottom;
    Node(int x) : data(x), next(NULL) , bottom(NULL) {}
};

Node* merge(Node* head1, Node* head2) {
    Node* head = new Node(0);
    Node* tail = head;

    while (head1 && head2) {
        if (head1->data <= head2->data) {
            tail->bottom = head1;
            head1 = head1->bottom;
        } else {
            tail->bottom = head2;
            head2 = head2->bottom;
        }
        tail = tail->bottom;
        tail->bottom = NULL;
    }

    if (head1) {
        tail->bottom = head1;
    } else {
        tail->bottom = head2;
    }

    return head->bottom;
}

// Node* flatten(Node* root) {
//     if (!root || !root->next) return root;

//     root->next = flatten(root->next);
//     root = merge(root, root->next);

//     return root;
// }
Node *flatten(Node *root) {
    // Your code here
    
    Node *h1 , *h2 , *h3;
    
    while(root->next != NULL){
        
        h1 = root;
        h2 = root->next;
        h3 = root->next->next;
        
        h1->next = NULL;
        h2->next = NULL;
        
        root = merge(h1,h2);
        
        root->next = h3;
    }
    
    return root;
}
// Function to print the linked list using the bottom pointer
void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->bottom;
    }
    cout << endl;
}

// Function to create a linked list from a given array
Node* createList(int arr[], int size) {
    if (size == 0) return NULL;
    Node* head = new Node(arr[0]);
    Node* tail = head;
    for (int i = 1; i < size; ++i) {
        tail->bottom = new Node(arr[i]);
        tail = tail->bottom;
    }
    return head;
}

int main() {
    // Creating a sample linked list
    Node* head = new Node(5);
    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);

    head->next = new Node(10);
    head->next->bottom = new Node(20);

    head->next->next = new Node(19);
    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);

    head->next->next->next = new Node(28);
    head->next->next->next->bottom = new Node(35);
    head->next->next->next->bottom->bottom = new Node(40);
    head->next->next->next->bottom->bottom->bottom = new Node(45);

    // Flatten the list
    head = flatten(head);

    // Print the flattened list
    printList(head);

    return 0;
}
