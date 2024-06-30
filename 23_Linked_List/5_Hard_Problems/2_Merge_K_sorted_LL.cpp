#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

Node* merge(Node* h1, Node* h2) {
    Node* head = new Node(0);
    Node* tail = head;

    while (h1 && h2) {
        if (h1->data <= h2->data) {
            tail->next = h1;
            h1 = h1->next;
        } else {
            tail->next = h2;
            h2 = h2->next;
        }
        tail = tail->next;
        tail->next = NULL;
    }

    if (h1) {
        tail->next = h1;
    } else {
        tail->next = h2;
    }

    return head->next;
}

void mergeSort(Node* arr[], int start, int end) {
    if (start >= end) {
        return;
    }

    int mid = start + (end - start) / 2;

    // Left sort
    mergeSort(arr, start, mid);

    // Right sort
    mergeSort(arr, mid + 1, end);

    // Merge the linked lists
    arr[start] = merge(arr[start], arr[mid + 1]);
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

// Function to print the linked list
void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}



// Function to merge K sorted linked lists
Node* mergeKLists(Node* arr[], int K) {
    // Using the merge sort approach

    // TC O(n*k*logk)
    // mergeSort(arr, 0, K - 1);
    // return arr[0];


    // using the Simple Method old 
    // TC O(n*k2)
    Node *head = arr[0];
     
    for(int i=1;i<K;i++){
        head = merge(head,arr[i]);
    }
     
    return head;
}

int main() {
    // Creating a sample input
    int K = 4;
    int arr1[] = {1, 2, 3};
    int arr2[] = {4, 5};
    int arr3[] = {5, 6};
    int arr4[] = {7, 8};

    Node* lists[K];
    lists[0] = createList(arr1, 3);
    lists[1] = createList(arr2, 2);
    lists[2] = createList(arr3, 2);
    lists[3] = createList(arr4, 2);

    // Merging the K sorted linked lists
    Node* mergedHead = mergeKLists(lists, K);

    // Printing the merged list
    printList(mergedHead);

    return 0;
}
