#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

Node* Reverse(Node* curr, Node* prev) {
    if (curr == NULL) {
        return prev;
    }
    Node* t = curr->next;
    curr->next = prev;
    return Reverse(t, curr);
}

struct Node* addTwoLists(struct Node* num1, struct Node* num2) {
    num1 = Reverse(num1, NULL);
    num2 = Reverse(num2, NULL);

    Node* curr1 = num1;
    Node* curr2 = num2;

    Node* head = new Node(0);
    Node* tail = head;

    int carry = 0;
    int sum = 0;

    while (curr1 && curr2) {
        sum = curr1->data + curr2->data + carry;

        tail->next = new Node(sum % 10);
        tail = tail->next;  // Advance tail

        curr1 = curr1->next;
        curr2 = curr2->next;
        carry = sum / 10;
    }

    while (curr1) {
        sum = curr1->data + carry;

        tail->next = new Node(sum % 10);
        tail = tail->next;  // Advance tail

        curr1 = curr1->next;
        carry = sum / 10;
    }

    while (curr2) {
        sum = curr2->data + carry;

        tail->next = new Node(sum % 10);
        tail = tail->next;  // Advance tail

        curr2 = curr2->next;
        carry = sum / 10;
    }

    while (carry) {
        tail->next = new Node(carry % 10);
        tail = tail->next;  // Advance tail

        carry /= 10;
    }

    head = Reverse(head->next, NULL);

    // Skip leading zeros if any
    while (head && head->data == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return head ? head : new Node(0);
}

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
    int arr1[] = {0, 8, 9, 8, 9, 0}; // This represents the number 089890
    int arr2[] = {1};                // This represents the number 1

    Node* num1 = createList(arr1, 6);
    Node* num2 = createList(arr2, 1);

    Node* result = addTwoLists(num1, num2);

    printList(result); // Expected output: 0 -> 8 -> 9 -> 9 -> 0 -> 1

    return 0;
}
