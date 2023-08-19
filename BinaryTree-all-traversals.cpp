#include <iostream>

//https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/

struct Node
{
    int data;
    struct Node *left, *right;
};

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// L-D-R
void printInorder(struct Node *node)
{
    if (node == NULL) return;

    printInorder(node->left);
    std::cout << node->data << " ";
    printInorder(node->right);
}

// D - L - R
void printPreOrder(struct Node *node)
{
    if (node == NULL)
        return;

    std::cout << node->data << " ";
    printPreOrder(node->left);
    printPreOrder(node->right);
}

// L - R -D
void postorder(struct Node *node)
{
    if (node == NULL)
        return;

    postorder(node->left);
    postorder(node->right);
    std::cout << node->data << " ";
}

int main()
{

    struct Node *node = newNode(1);
    node->left = newNode(2);
    node->right = newNode(3);
    node->left->left = newNode(4);
    node->left->right = newNode(5);
    node->right->left = newNode(6);
    node->right->right = newNode(7);

    std::cout << " Inorder traversal: ";
    printInorder(node);

    std::cout << std::endl;

    std::cout << " Preorder traversal: ";
    printPreOrder(node);

    std::cout << std::endl;

    std::cout << " Postorder traversal: ";
    postorder(node);
    std::cout << std::endl;

    return 0;
}
