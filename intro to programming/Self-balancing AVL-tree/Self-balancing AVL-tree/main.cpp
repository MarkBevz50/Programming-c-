#include <iostream>
#include "Tree.h"


int main() {
    Node* root = nullptr;
    std::cout << "Enter height of tree: ";
    int treeHeight;
    std::cin >> treeHeight;
    // Insert elements into the AVL tree
    for (int i = 1; i <= treeHeight; ++i) {
        root = insert(root, i);
    }

    std::cout << "AVL Tree (Graph representation) before deletion:" << std::endl;
    printTreeGraph(root);

    int condition;
    std::cout << "Enter the element you want to delete: ";
    std::cin >> condition;

    root = deleteNode(root, condition);

    std::cout << "AVL Tree (Graph representation) after deletion:" << std::endl;
    printTreeGraph(root);
    std::cout << std::endl;

    return 0;
}