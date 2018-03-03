#include <iostream>

struct ListEntry {
    ListEntry *next;
    ListEntry **prev;
    int data;
};

struct List {
    ListEntry *head;
    ListEntry **nextOfLastEntry;
    int count;
};

void AppendToTail(List *l, ListEntry *elm)
{
    elm->next = NULL;
    elm->prev = l->nextOfLastEntry;
    *(l->nextOfLastEntry) = elm;
    l->nextOfLastEntry = &elm->next;
    ++l->count;
}

void RemoveTail(List *l)
{
    ListEntry *last = (ListEntry *)l->nextOfLastEntry;
    *last->prev = NULL;
    l->nextOfLastEntry = last->prev;
//  delete last;
    --l->count;
}

/* NULL if list is empty */
ListEntry * Head(List *l)
{
    return l->head;
}

ListEntry * End(List *l)
{
    return NULL;
}

/* NULL if list is empty */
ListEntry * Tail(List *l)
{
#if 0
    if (NULL != Head(l)) {
        return (ListEntry *)l->nextOfLastEntry;
    } else {
        return NULL;
    }
#endif
    return *((ListEntry *)l->nextOfLastEntry)->prev;
}

ListEntry *Previous(ListEntry *elm)
{
    return *(((ListEntry *)(elm->prev))->prev);
}

ListEntry *Next(ListEntry *elm)
{
    return elm->next;
}

#define for_each(elm, list) \
    for ((elm) = Head((list)); (elm) != End((list)); (elm) = (elm)->next)

#define for_each_reverse(elm, list) \
    for ((elm) = Tail((list)); (elm) != End((list)); \
            (elm) = Previous((elm)))

#if 0
int main()
{
    List l;
    l.head = NULL;
    l.nextOfLastEntry = &l.head;
    l.count = 0;

    ListEntry *elm1 = new ListEntry;
    elm1->data = 1;
    AppendToTail(&l, elm1);

    ListEntry *elm2 = new ListEntry;
    elm2->data = 2;
    AppendToTail(&l, elm2);

    std::cout << (void *)elm2->prev << std::endl;
    std::cout << (void *)elm1 << std::endl;
    std::cout << (void *)&elm1->next << std::endl;

    ListEntry *elm3;
    elm3 = Tail(&l);

    std::cout << (void *)elm2 << std::endl
        << (void *)elm3 << std::endl;

    elm3 = Previous(Head(&l));
    std::cout << (void *)elm3 << std::endl;

    List l2;
    l2.head = NULL;
    l2.nextOfLastEntry = &l2.head;

    std::cout << "going travrse empty list " << std::endl;
    for_each(elm3, &l2) {
        std::cout << elm3->data << std::endl;
    }
    for_each_reverse(elm3, &l2) {
        std::cout << elm3->data << std::endl;
    }

    std::cout << "going to loop" << std::endl;
    for_each(elm3, &l) {
        std::cout << elm3->data << std::endl;
    }

    std::cout << "going to reverse loop" << std::endl;
    for_each_reverse(elm3, &l) {
        std::cout << elm3->data << std::endl;
    }

    std::cout << "going to remove!" << std::endl;
    while (Head(&l)) {
        RemoveTail(&l);
    }

    std::cout << "going to traverse!" << std::endl;
    for_each(elm3, &l) {
        std::cout << elm3->data << std::endl;
    }
}
#endif


