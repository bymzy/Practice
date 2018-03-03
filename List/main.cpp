//
// Created by 明正莹 on 2018/3/3.
//

#include <assert.h>
#include <iostream>
#include "GenericTailq.hpp"

int main(int argc, char *argv[])
{
    ListItemType(int, IntListItem);
    ListType(IntListItem, IntList);

    IntList l;
    InitList(&l);

    IntListItem item1;
    InitItem(&item1);
    item1.value = 1;

    IntListItem item2;
    InitItem(&item2);
    item2.value = 2;

    AppendToTail(&l, &item1);
    AppendToTail(&l, &item2);

    IntListItem *item3 = NULL;

    assert(Tail(&l, IntListItem) == &item2);
    assert(Head(&l) == &item1);
    assert(NextItem(&item1) == &item2);

    std::cout << "forward travel " << std::endl;
    ForEachListItem(item3, &l) {
        std::cout << item3->value << std::endl;
    }

    RemoveItem(&l, &item1, IntListItem);
    item3 = Head(&l);
    assert(NULL == PreviousItme(item3, IntListItem));

    std::cout << "backward travel " << std::endl;
    ForEachReverseListItem(item3, &l, IntListItem) {
        std::cout << item3->value << std::endl;
    }

    while (l.count > 0) {
        RemoveTail(&item3, &l, IntListItem);
    }

    std::cout << "after remove " << std::endl;
    ForEachReverseListItem(item3, &l, IntListItem) {
        std::cout << item3->value << std::endl;
    }

    return 0;
}


