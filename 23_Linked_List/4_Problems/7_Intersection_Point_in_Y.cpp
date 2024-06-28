#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Function to find the intersection point of two linked lists
int intersectPoint(Node* head1, Node* head2) {
    if (head1 == NULL || head2 == NULL) return -1;

    // Count the nodes in both linked lists
    Node *curr1 = head1;
    Node *curr2 = head2;
    int count1 = 0, count2 = 0;
    
    while (curr1 != NULL) {
        count1++;
        curr1 = curr1->next;
    }
    
    while (curr2 != NULL) {
        count2++;
        curr2 = curr2->next;
    }
    
    // Reset pointers to the heads of the linked lists
    curr1 = head1;
    curr2 = head2;
    
    // Move the pointer of the longer list ahead by the difference in lengths
    if (count1 > count2) {
        int diff = count1 - count2;
        while (diff--) {
            curr1 = curr1->next;
        }
    } else {
        int diff = count2 - count1;
        while (diff--) {
            curr2 = curr2->next;
        }
    }
    
    // Move both pointers until they intersect
    while (curr1 != NULL && curr2 != NULL) {
        if (curr1 == curr2) {
            return curr1->data;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    
    // If no intersection is found
    return -1;
}

// using slow and the fast Pointer
int intersectPointMethod2(Node* head1, Node* head2)
{
    
    if (head1 == NULL || head2 == NULL) return -1;
    
    Node *curr1 = head1;
    Node *curr2 = head2;
    
    while(curr1->next != NULL){
        curr1 = curr1->next;
    }
    
    curr1->next = head1;
    
    
    Node *fast = head2;
    Node *slow = head2;
    
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            break;
        }
    }
    
    
    if(fast == NULL || fast->next == NULL){
        return -1;
    }
    
    slow = head2;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }

    return slow->data;

}
// Helper function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Creating two linked lists with an intersection point
    Node* newNode;
    
    // List 1: 10 -> 3 -> 6 -> 15 -> 30
    Node* head1 = new Node(10);
    head1->next = new Node(3);
    head1->next->next = new Node(6);
    newNode = new Node(15);
    head1->next->next->next = newNode;
    head1->next->next->next->next = new Node(30);

    // List 2: 8 -> 9 -> 15 -> 30
    Node* head2 = new Node(8);
    head2->next = new Node(9);
    head2->next->next = newNode;
    
    cout << "List 1: ";
    printList(head1);

    cout << "List 2: ";
    printList(head2);
    
    // int intersection = intersectPoint(head1, head2);
    int intersection = intersectPointMethod2(head1, head2);
    if (intersection != -1) {
        cout << "The intersection point is: " << intersection << endl;
    } else {
        cout << "There is no intersection point." << endl;
    }

    return 0;
}
