//
// Created by 明正莹 on 2018/2/28.
//
// 模版化的单向链表

#include <errno.h>
#include <stdio.h>

#define NodeType(KeyType, ValueType, NodeTypeName) typedef struct NodeTypeName{ \
    KeyType key; \
    ValueType value; \
    NodeTypeName *next; \
}NodeTypeName; \
\
typedef int (* NodeTypeNameCmp) (KeyType *left, KeyType *right);


#define ListType(NodeTypeName, ListTypeName) typedef struct ListTypeName { \
    int (*CmpFunc) (void *left, void *right); \
    void (*DebugFunc) (void *node); \
    NodeTypeName *head; \
    NodeTypeName *tail; \
}ListTypeName;


/* min --> max */

#define InsertNode(NodeTypeName, targetList, item, err) do { \
    NodeTypeName *head = (targetList)->head; \
    if (NULL == head) { \
        (targetList)->head = (item); \
        (targetList)->tail = (item); \
        (err) = 0; \
        break; \
    } \
\
    int ret = 0; \
    NodeTypeName *prev = head; \
    NodeTypeName *next= head->next; \
    do { \
        next = prev->next; \
        ret = (targetList)->CmpFunc(&prev->key, &(item)->key); \
        if (0 == ret) { \
            (err) = EEXIST; \
            break; \
        } else if (ret < 0) { \
            prev = next; \
        } else { \
            break; \
        } \
    } while (prev != NULL); \
\
    if (0 != (err)) { \
        break; \
    } \
\
    if (prev != NULL) { \
        if (head == prev) { \
            (targetList)->head = item; \
        } \
        (item)->next = prev; \
    } else { \
        (targetList)->tail->next = item; \
        (targetList)->tail = item; \
    }\
\
} while(0);

#define Head(targetList) (targetList)->head
#define Next(node) node->next
#define End(targetList) NULL

/* loop */
#define ForEachList(var, targetList) \
    for ((var) = Head((targetList)); (var) != End((targetList)); (var) = Next((var)))

int Cmp(void *left, void *right)
{
    int a = *(int *)left;
    int b = *(int *)right;

    //printf("%d, %d \n", a, b);
    if (a > b) {
        return 1;
    } else if (a < b) {
        return -1;
    } else {
        return 0;
    }
}

void Debug(void *node)
{
    int *val = (int *) node;
    printf("%d\n", *val);
}

NodeType(int, int, IntNode);
ListType(IntNode, IntList);

#if 0
int main()
{
    IntNode node1;
    node1.key = 1;
    node1.value = 1;
    node1.next = NULL;

    IntNode node2;
    node2.key = 2;
    node2.value = 2;
    node2.next = NULL;

    IntNode node3;
    node3.key = 3;
    node3.value = 3;
    node3.next = NULL;

    IntList l;
    l.head = NULL;
    l.CmpFunc = Cmp;
    l.DebugFunc = Debug;

    int err = 0;
    InsertNode(IntNode, &l, &node2, err);
    InsertNode(IntNode, &l, &node1, err);
    InsertNode(IntNode, &l, &node3, err);

    IntNode * head = l.head;
    while (head) {
        l.DebugFunc(&head->value);
        head = head->next;
    }

    IntNode *ite;
    ForEachList(ite, &l) {
        l.DebugFunc(&ite->value);
    }

    return 0;
}

#endif

