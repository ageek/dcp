#include <iostream>

class Node
{
public:
    int data;
    Node *next;
};

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

Node *head = newNode(-999);

// insert at the end of the list
void insert(int data)
{
    std::cout << "Inserting " << data << std::endl;
    Node *node = newNode(data);

    // is it first node? point head to this node
    if (head->next == NULL && head->data == -999)
        head = node;

    Node *ptr = head;
    // else traverse till end and insert
    while (ptr->next)
    {
        ptr = ptr->next;
    }
    // insert new node
    if ((ptr != node) && (ptr->next == NULL))
    {
        ptr->next = node;
    }
}

void printList()
{
    Node *ptr;
    ptr = head;
    do
    {
        std::cout << ptr->data << ", ";
        ptr = ptr->next;
    } while (ptr != NULL);
}

int main()
{
    for (int i = 10; i <= 100; i += 10)
    {
        insert(i);
    }
    printList();
}
