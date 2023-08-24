#include <iostream>

class Node {
public:
    int data;
    Node *prev;
    Node *next;
};

Node *newNode(int data) {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

Node *head = newNode(-999);
Node *tail = newNode(-999);

// insert at the end
void insertData(int data) {
    std::cout << "Inserting " << data << std::endl;

    Node *node = newNode(data);

    // if this is first node
    if (head->data == -999)
        head = node;

    Node *ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    // insert now
    if (ptr != node && ptr->next == NULL) {
        ptr->next = node;
        node->prev = ptr;
    }
    // tail always points to the newly added node
    tail = node;
}

void printForward() {
    std::cout << std::endl
              << "Printing forward" << std::endl;
    Node *ptr;
    ptr = head;
    do {
        std::cout << ptr->data << ", ";
        ptr = ptr->next;
    } while (ptr != NULL);
}

void printBackward() {
    std::cout << std::endl
              << "Printing backward" << std::endl;
    Node *ptr;
    ptr = tail;
    do {
        std::cout << ptr->data << ", ";
        ptr = ptr->prev;
    } while (ptr != NULL);
}

int main() {
    for (int i = 11; i <= 100; i += 10) {
        insertData(i);
    }

    printForward();
    printBackward();
}