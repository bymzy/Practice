
#ifndef __BST_HPP_
#define __BST_HPP_

#include <errno.h>
#include <iostream>

template<typename KeyType, typename ValueType>
struct BSTNode {
    KeyType key;
    ValueType value;
    struct BSTNode *parent;
    struct BSTNode *leftChild;
    struct BSTNode *rightChild;
};

template<typename KeyType, typename ValueType>
struct BSTTree {
    struct BSTNode<KeyType, ValueType> *root;
    int nodeCount;
};

template<typename KeyType, typename ValueType>
struct BSTIterator {
    struct BSTTree<KeyType, ValueType> *tree;
    struct BSTNode<KeyType, ValueType> *current;
};

template<typename T>
int KeyCompare(T left, T right)
{
    if (left > right) {
        return 1;
    } else if (left < right) {
        return -1;
    } else {
        return 0;
    }
}

template<typename KeyType, typename ValueType>
struct BSTNode<KeyType, ValueType> **
InnerSearch(struct BSTNode<KeyType, ValueType> **ppNode,
        struct BSTNode<KeyType, ValueType> **ppParent,
        const KeyType& key)
{
    if ((*ppNode) == NULL) {
        return ppNode;
    }

    /* find target key */
    int ret = KeyCompare((*ppNode)->key, key);
    if (ret == 0) {
        return ppNode;
    }

    if (ppParent != NULL) {
        *ppParent = *ppNode;
    }

    /* recursively search */
    struct BSTNode<KeyType, ValueType> **next;
    next = (ret > 0) ? &((*ppNode)->leftChild) : &((*ppNode)->rightChild);

    return InnerSearch(next, ppParent, key);
}

template<typename KeyType, typename ValueType>
int InsertNode(
        struct BSTTree<KeyType, ValueType> *tree,
        const KeyType& key,
        const ValueType& value,
        struct BSTNode<KeyType, ValueType> **out)
{
    int err = 0;
    struct BSTNode<KeyType, ValueType> **ppNode = NULL;
    struct BSTNode<KeyType, ValueType> *pParent = NULL;
    ppNode = InnerSearch(&tree->root, &pParent, key);
    if (*ppNode != NULL) {
        err = EEXIST;
        if (out != NULL) {
            *out = *ppNode;
        }
        return err;
    }

    struct BSTNode<KeyType, ValueType> *newNode = new BSTNode<KeyType, ValueType>;
    newNode->key = key;
    newNode->value = value;
    newNode->parent = pParent;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;

    *ppNode = newNode;
    if (out != NULL) {
        *out = newNode;
    }

    return err;
}

template<typename KeyType, typename ValueType>
struct BSTNode<KeyType, ValueType> *FindNode(
        struct BSTTree<KeyType, ValueType> *tree,
        const KeyType& key)
{
    struct BSTNode<KeyType, ValueType> **ppNode = NULL;
    ppNode = InnerSearch(&tree->root, NULL, key);
    return *ppNode;
}

template<typename KeyType, typename ValueType>
int DeleteNode(
        struct BSTTree<KeyType, ValueType> *tree,
        const KeyType& key)
{
    int err = 0;
    bool delRoot = false;
    struct BSTNode<KeyType, ValueType> **ppNode = NULL;
    struct BSTNode<KeyType, ValueType> *pParent = NULL;
    ppNode = InnerSearch(&tree->root, &pParent, key);
    if (*ppNode == NULL) {
        err = ENOENT;
        return err;
    }

    /* ppNode is the child pointer of pParent */
    struct BSTNode<KeyType, ValueType> *toDel= *ppNode;
    struct BSTNode<KeyType, ValueType> *temp= NULL;

    if (toDel->rightChild == NULL && toDel->leftChild == NULL) {
        *ppNode = NULL;
    } else if (toDel->leftChild != NULL && toDel->rightChild == NULL) {
        *ppNode = toDel->leftChild;
        (*ppNode)->parent = pParent;
    } else if (toDel->leftChild == NULL && toDel->rightChild != NULL) {
        (*ppNode) = toDel->rightChild;
        (*ppNode)->parent = pParent;
    } else {
        /* !NULL, !NULL */
        pParent = NULL;
        temp = toDel->rightChild;
        while (temp->leftChild != NULL) {
            pParent = temp;
            temp = temp->leftChild;
        }

        toDel->key = temp->key;
        toDel->value = temp->value;
        if (pParent != NULL){
            pParent->leftChild = NULL;
        }

        if (temp == toDel->rightChild) {
            toDel->rightChild = temp->rightChild;
            temp->rightChild->parent = toDel;
        }

        toDel = temp;
    }

    delete toDel;
    return err;
}

template<typename KeyType, typename ValueType>
struct BSTNode<KeyType, ValueType> *BSTGetFirst(
        struct BSTIterator<KeyType, ValueType> *iter)
{
    struct BSTNode<KeyType, ValueType> *node = iter->tree->root;
    if (node == NULL) {
        return NULL;
    }

    while (node->leftChild != NULL) {
        node = node->leftChild;
    }

    iter->current = node;
    return node;
}

template<typename KeyType, typename ValueType>
struct BSTNode<KeyType, ValueType> *BSTGetNext(
        struct BSTIterator<KeyType, ValueType> *iter)
{
    struct BSTNode<KeyType, ValueType> *node = iter->current;
    struct BSTNode<KeyType, ValueType> *parent = node->parent;

    if (node->rightChild != NULL) {
        node = node->rightChild;
        while (node->leftChild != NULL) {
            node = node->leftChild;
        }
        iter->current = node;
        return node;
    } else {
        while (parent != NULL && parent->rightChild == node) {
            node = parent;
            parent = node->parent;
        }
        iter->current = parent;
        return parent;
    }
}

#endif


