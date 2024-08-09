#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class ListNode {
public:
    int val;
    ListNode *next;

    ListNode(int data) {
        val = data;
        next = NULL;
    }
};

// Helper function to build the BST from sorted vector
Node* buildBST(vector<int>& tree, int start, int end) {
    if (start > end) return NULL;
    int mid = start + (end - start) / 2;
    Node* root = new Node(tree[mid]);
    root->left = buildBST(tree, start, mid - 1);
    root->right = buildBST(tree, mid + 1, end);
    return root;
}

// Function to convert sorted linked list to BST
Node* sortedListToBST(ListNode* head) {
    vector<int> tree;
    while (head) {
        tree.push_back(head->val);
        head = head->next;
    }
    return buildBST(tree, 0, tree.size() - 1);
}

// Utility function to print inorder traversal of the tree
void printInorder(Node* node) {
    if (node == NULL) return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

int main() {
    // Example to create a sorted linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Node* root = sortedListToBST(head);

    cout << "Inorder traversal of the constructed BST: ";
    printInorder(root);
    cout << endl;

    return 0;
}
