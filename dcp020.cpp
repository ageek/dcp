// dcp-020
// This problem was asked by Google.

// Given two singly linked lists that intersect at some point, find the intersecting node.
// The lists are non-cyclical.
// For example, given A = 3 -> 7 -> 8 -> 10 and B = 99 -> 1 -> 8 -> 10, return the node with value 8.
// In this example, assume nodes with the same value are the exact same node objects.
// Do this in O(M + N) time (where M and N are the lengths of the lists) and constant space.

#include <iostream>
#include <set>

struct Node {
    int data;
    struct Node *next;
};

Node *newNode(int data) {
    Node *node = new Node();
    node->data = data;
    node->next = NULL;

    return node;
}

void printList(Node *myroot) {
    Node *root = myroot;
    while (root != NULL) {
        std::cout << root->data << ",";
        root = root->next;
    }
    std::cout << std::endl;
}

void insert(Node *myroot, int val[], int size) {
    Node *temp = myroot;
    for (int ix = 0; ix < size; ix++) {
        Node *node = newNode(val[ix]);
        if (myroot != NULL && myroot->data == -99) {
            myroot = node;
        } else
            temp->next = node;

        // finally
        temp = node;
    }
}
int main() {
    Node *root1 = newNode(99);
    root1->next = newNode(3);
    root1->next->next = newNode(5);
    root1->next->next->next = newNode(8);
    root1->next->next->next->next = newNode(10);
    printList(root1);

    Node *root2 = newNode(33);
    root2->next = newNode(53);
    root2->next->next = root1->next->next->next;
    // add the intersecting node
    // root2->next->next->next = root1->next->next->next;
    printList(root2);


    // 1st approach:
    // Finds intersecting node of two SLL in O(m+ n) time
    // also takes O(max(m,n)) space 
    
    // iterate over list1 and add all of them to a set
    std::set<struct Node *> nodeSet;
    Node *temp = root1;
    while (temp->next != NULL) {
        nodeSet.insert(temp);
        temp = temp->next;
    }

    // iterate over the second and keep looking for the node in nodeSet
    temp = root2;
    while (temp->next != NULL) {
        if (nodeSet.find(temp) != nodeSet.end()) {
            std::cout << "Intersecting node : " << temp->data << std::endl;
            break;
        } else
            temp = temp->next;
    }

    // 2nd approach: 
    // time = O(m+n)
    // space = O(1) i.e. constant space
    // Idea: Have two pointers. Jump longer list's pointer by len(longer list) - len(shorter list)
    //       Then move both simultaneously and keep checking for a matching node
    int len1 = 0, len2 = 0;

    temp = root1;
    while (temp != NULL) {
        temp = temp->next;
        len1++;
    }
    temp = root2;
    while (temp != NULL) {
        temp = temp->next;
        len2++;
    }
    int delta = (len1 > len2) ? len1 - len2 : len2 - len1;
    std::cout << "len1 =" << len1 << " len2 =" << len2 << ", and delta=" << delta << std::endl;
    Node *longer, *shorter; // make len(longer) > len(shorter)
    if (len1 > len2) {
        longer = root1;
        shorter = root2;
    } else {
        longer = root2;
        shorter = root1;
    }
    // move longer by delta
    while (delta-- > 0)
        longer = longer->next;

    // move one step simultaneously and check for match
    while (longer->next != NULL) {
        if (longer == shorter) {
            std::cout << "Intersecting node : " << longer->data << std::endl;
            break;
        } else {
            longer = longer->next;
            shorter = shorter->next;
        }
    }

    return 0;
}