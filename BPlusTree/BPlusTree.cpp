//
// Created by bymzy@outlook.com on 2018/3/6.
//

#include <stdlib.h>
#include <errno.h>

typedef uint16_t indx_t;

struct BTVal {
    int size;
    char *data;
};

struct BTreePage {
#define BP_leaf     0x00000001
#define BP_branch   0x00000002

    int bpType;
    indx_t lowerBound;
    indx_t upperBound;
    int nodeCount;
    indx_t nodePtr[1]; /* address of node in this page */
};

struct BTreeNode {
    int keySize; /* include \0, and we use strcmp to compare key */
    int dataSize;
    char data[1]; /* key and data is both appended here */
};

#define NODE_HEADER_SIZE offsetof(BTreeNode, data)
#define NODE_key(node) ((node) + sizeof(int) * 2)
#define NODE_data(node) ((node) + sizeof(int) * 2 + (node)->keySize)

int bt_malloc_page(BTreePage **ret)
{
    *ret = (struct BTreePage*)malloc(sizeof(BTreePage));
    if (NULL == *ret) {
        return errno;
    }
    return 0;
}

int bt_page_search_node(BTreePage *page, BTVal *key, BTreeNode **node)
{
    int err = 0;
    int i = 0, j = 0;
    int lt = 0, ge = 0;
    int low = 0, high = page->nodeCount - 1;
    int mid = 0;

    /* use binary search to locate */
    while (low <= high) {
        mid = low + (high - low) >> 1;
    }


    return err;
}

int bt_page_add_node(BTreePage *page, BTVal *key, BTVal *data)
{
    int err = 0;
    int i = 0, j = 0;
    for (;i < page->nodeCount; ++i) {
    }

    return err;
}


