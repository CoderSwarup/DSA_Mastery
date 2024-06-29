#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};



// Function to print the linked list
void printList(Node* node) {
    while (node != NULL) {
        cout << node->data;
        if (node->next != NULL)
            cout << " -> ";
        node = node->next;
    }
    cout << endl;
}

// Function to create a linked list from a given array
Node* createList(int arr[], int size) {
    if (size == 0) return NULL;
    Node* head = new Node(arr[0]);
    Node* tail = head;
    for (int i = 1; i < size; ++i) {
        tail->next = new Node(arr[i]);
        tail = tail->next;
    }
    return head;
}

int main() {
    int arr1[] = {2,3,4,6,8,7,5,9,11,18}; 
    // OUTPUT 2 -> 3 -> 4 -> 6 -> 9-> 5 -> 7 -> 8 -> 11 -> 18

    Node* num1 = createList(arr1, sizeof(arr1)/sizeof(int));
    Node *point = num1->next->next->next;

    Node *first = point;
    Node *second = first->next;

    int x = 4;
    Node *prev = first;
    Node *curr = second;
    while(x-- && curr){
        Node *f = curr->next;
        curr->next = prev;
        prev = curr;
        curr = f;
    }

    first->next = prev;
    second->next = curr;




    printList(num1); 

    return 0;
}
