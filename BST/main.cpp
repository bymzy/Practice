

#include <assert.h>
#include <iostream>
#include "bst.hpp"

int main()
{
    struct BSTTree<int, int> *tree = new BSTTree<int, int>;
    tree->nodeCount = 0;

    struct BSTNode<int, int> *node;
    InsertNode(tree, 1, 1, &node);
    assert(node->key == 1);
    InsertNode(tree, 3, 3, &node);
    InsertNode(tree, 2, 2, &node);
    InsertNode(tree, 10, 10, &node);
    InsertNode(tree, 20, 20, &node);


    struct BSTIterator<int, int> iter;
    struct BSTNode<int, int> *temp = NULL;
    iter.tree = tree;
    iter.current = NULL;

    DeleteNode(tree, 1);
    temp = BSTGetFirst(&iter);
    std::cout << temp->key << std::endl;

    while (temp = BSTGetNext(&iter)) {
        std::cout << temp->key << std::endl;
    }

    DeleteNode(tree, 3);
    temp = BSTGetFirst(&iter);
    std::cout << temp->key << std::endl;

    while (temp = BSTGetNext(&iter)) {
        std::cout << temp->key << std::endl;
    }
    return 0;
}


