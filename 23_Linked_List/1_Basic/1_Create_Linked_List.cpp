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


int main(){


    Node *n1 = new Node(20);
    Node *n2 = new Node(30);

    cout << n1->data << endl;
    cout << n1->next << endl;
    cout << n2->data << endl;
    cout << n2->next << endl;


return 0;
}


//why we alwasy create a node dynamically in linkedn list
// There are several reasons why we typically create nodes dynamically in a linked list:

// 1. Flexibility: Dynamic memory allocation allows us to create nodes on the fly, as needed, without having to declare a fixed number of nodes at compile-time. This makes our linked list more flexible and adaptable to changing requirements.

// 2. Efficient Memory Usage: When we create nodes dynamically, we only allocate memory for the nodes that are actually needed. This is in contrast to declaring an array of nodes, where we would need to allocate memory for a fixed number of nodes, even if we don't end up using them all.

// 3. Dynamic Size: Linked lists can grow or shrink dynamically as nodes are added or removed. Dynamic memory allocation allows us to easily manage this dynamic size, without having to worry about running out of space or wasting memory.

// 4. Avoiding Stack Overflow: If we were to declare nodes as local variables on the stack, we would be limited by the stack size. Dynamic memory allocation allows us to allocate memory on the heap, which is much larger than the stack, reducing the risk of stack overflow.

// 5. Node Lifetime: When we create nodes dynamically, we have control over their lifetime. We can create nodes, use them, and then delete them when they're no longer needed, which helps prevent memory leaks.

// 6. Decoupling Node Creation from Node Management: By creating nodes dynamically, we decouple the creation of nodes from the management of the linked list. This makes it easier to implement linked list operations, such as insertion, deletion, and traversal, without worrying about the underlying memory management.
