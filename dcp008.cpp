// dcp-008
// This problem was asked by Google.
// A unival tree (which stands for "universal value") is a tree where all nodes under it have the same value.
// Given the root to a binary tree, count the number of unival subtrees.
// For example, the following tree has 5 unival subtrees:
//    0
//   / \
//  1   0
//     / \
//    1   0
//   / \
//  1   1

#include <iostream>

struct Node {
    int data;
    Node *left = nullptr;
    Node *right = nullptr;
};

Node *newNode(int data) {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;

    return newNode;
}

// L-D-R
void printInorder(struct Node *node) {
    if (node == NULL)
        return;

    printInorder(node->left);
    std::cout << node->data << " ";
    printInorder(node->right);
}

bool isUnival(Node *root, int val) {
    if (root->left == nullptr && root->right == nullptr) {
        return true;
    } else if (root->data == val) {
        return (isUnival(root->left, val) && isUnival(root->right, val));
    } else {
        return false;
    }
}

int countUnival(Node *root) {
    if (root == nullptr)
        return 0;
    int left = countUnival(root->left);
    int right = countUnival(root->right);
    if (isUnival(root, root->data))
        return 1 + left + right;
    else
        return left + right;
}

int main() {
    // For example, the following tree has 7 unival subtrees:
    //    0
    //   / \
    //  1   0
    //     /   \
    //    1     0
    //   / \   / \
    //  1   1  0  0

    Node *root2 = newNode(0);
    root2->left = newNode(1);
    root2->right = newNode(0);

    root2->right->left = newNode(1);
    root2->right->right = newNode(0);

    root2->right->left = newNode(1);
    root2->right->right = newNode(0);

    root2->right->right->left = newNode(0);
    root2->right->right->right = newNode(0);

    root2->right->left->left = newNode(1);
    root2->right->left->right = newNode(1);

    std::cout << std::endl
              << " Unival Tree count = " << countUnival(root2) << std::endl;
}