//
// Created by 明正莹 on 2018/3/3.
//
// 模版化的双向链表

#ifndef PRACTICE_GENERICTAILQ_HPP
#define PRACTICE_GENERICTAILQ_HPP

// @prev address of @next of previous item (== address of prev item)
#define ListItemType(ValueType, ItemTypeName) typedef struct ItemTypeName { \
    ItemTypeName *next; \
    ItemTypeName **prev; \
    ValueType value; \
}ItemTypeName

#define ListType(ItemTypeName, ListTypeName) typedef struct ListTypeName { \
    ItemTypeName *head; \
    ItemTypeName **nextOfLastItem; \
    int count; \
} ListTypeName

#define InitItem(item) do { \
    (item)->next = NULL; \
    (item)->prev = NULL; \
} while(0);

#define InitList(targetList) do { \
    (targetList)->head = NULL; \
    (targetList)->count = 0; \
    (targetList)->nextOfLastItem = &((targetList)->head); \
} while(0);

#define Head(targetList) (targetList)->head
#define Tail(targetList, ItemTypeName) *((ItemTypeName *) \
    ((targetList)->nextOfLastItem))->prev
#define End(targetList) NULL

#define NextItem(item) (item)->next
#define PreviousItme(item, ListItemType) *(((ListItemType *)((item)->prev))->prev)

#define AppendToTail(targetList, item) do { \
    (item)->next = NULL; \
    (item)->prev = (targetList)->nextOfLastItem; \
    *((targetList)->nextOfLastItem) = (item); \
    (targetList)->nextOfLastItem = &((item)->next); \
    ++(targetList)->count; \
} while(0);

/* we just remove item from list
 * if pItem is not NULL, then tail is stored in *pItem
 * */

#define RemoveTail(pItem, targetList, ItemTypeName) do { \
    if (NULL != (pItem)) { \
        *pItem = Tail(targetList, ItemTypeName); \
    } \
    *(((ItemTypeName *)(targetList)->nextOfLastItem)->prev) = NULL; \
    (targetList)->nextOfLastItem = ((ItemTypeName *)(targetList)->nextOfLastItem)->prev; \
    --(targetList)->count; \
} while(0);

#define RemoveItem(targetList, item, ItemTypeName) do { \
    if ((item)->next == NULL) { \
        ItemTypeName *temp; \
        RemoveTail(&temp, targetList, ItemTypeName); \
        break; \
    } \
    (item)->next->prev = (item)->prev; \
    *((item)->prev) = (item)->next; \
    --(targetList)->count; \
} while(0);

#define ForEachListItem(item, targetList) \
    for ((item) = Head(targetList); (item) != End(targetList); (item) = NextItem(item))

#define ForEachReverseListItem(item, targetList, ListItemType) \
    for ((item) = Tail(targetList, ListItemType); (item) != End(targetList); \
            (item) = PreviousItme(item, ListItemType))

#endif //PRACTICE_GENERICTAILQ_HPP
