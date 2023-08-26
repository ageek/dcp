//https://www.geeksforgeeks.org/xor-linked-list-a-memory-efficient-doubly-linked-list-set-1/?ref=lbp

// XOR linked list: memory efficient doubly linked list
// dcp-006
// This problem was asked by Google.

// An XOR linked list is a more memory efficient doubly linked list. Instead of each node holding 
// next and prev fields, it holds a field named both, which is an XOR of the next node and the 
// previous node. Implement an XOR linked list; it has an add(element) which adds the element to 
// the end, and a get(index) which returns the node at index.
// If using a language that has no pointers (such as Python), you can assume you have access to 
// get_pointer and dereference_pointer functions that converts between nodes and memory addresses.

#include <iostream>

struct Node {
    int data;
    Node *nxp;
};

Node *newNode(int data) {
    Node *node = new Node();
    node->data = data;
    // next XOR prev node's address
    node->nxp = nullptr;
    return node;
}

Node *head;
Node *tail;

Node *XOR(Node *A, Node *B) {
    // reinterpret_cast<uintptr_t>(A) and reinterpret_cast<uintptr_t>(B):
    // These lines are casting the memory addresses of pointers A and B to the uintptr_t type.
    // uintptr_t is an unsigned integer type capable of holding a pointer value without loss of data.
    // This step essentially converts the pointer values to integers.

    // reinterpret_cast<Node *>:
    // This part of the code is casting the result of the XOR operation back to a pointer type.
    // It's indicating that the result will be treated as a pointer to a Node object.

    // reinterpret_cast<Node *> (...) ^ (...):
    // This XOR operation is performed on the two integer values obtained from casting the memory
    // addresses of pointers A and B.

    return reinterpret_cast<Node *>(reinterpret_cast<uintptr_t>(A) ^ reinterpret_cast<uintptr_t>(B));
}

// insert at the end
void insetData(int data) {
    std::cout << "Inserting data " << data << std::endl;

    Node *node = newNode(data);

    // a ^ a = 0
    // a ^ 0 = a
    // first node check
    if (head == nullptr) {
        head = node;
        tail = node;
    } else {
        // else use tail to insert at the end
        node->nxp = tail;

        tail->nxp = XOR(tail->nxp, node);
        tail = node;
    }
}

void printForward() {
    std::cout << "Printing forward list" << std::endl;
    Node *curr = head;
    Node *prev = nullptr;
    Node *next;

    while (curr != nullptr) {
        std::cout << curr->data << ", ";
        next = XOR(prev, curr->nxp);
        prev = curr;
        curr = next;
    }
}

int main() {
    for (int i = 11; i <= 100; i += 10) {
        insetData(i);
    }
    printForward();
}   