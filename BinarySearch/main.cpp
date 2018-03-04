//
// Created by bymzy@outlook.com on 2018/3/3.
//

#include <assert.h>
#include <iostream>
#include "BinarySearch.hpp"

int IntCompare(const int *left, const int *right)
{
    if (*left > *right) {
        return 1;
    } else if (*left < *right) {
        return -1;
    } else {
        return 0;
    }
}


int main()
{
    int data[20] = {0,3,6,9,12,15,18,21,24,27};

    int key = 0;
    int ret = 0;
    int lt = 0;
    int ge = 0;
    int size = 10;

    for (int i=0; i < size; ++i) {
        std::cout << data[i] << ",";
    }
    std::cout << std::endl;

#if 0
    std::cout << "try binary search" << std::endl;
    ret = BinarySearch(data, size, 0, ge, lt);
    assert(ret == 0);
    std::cout << ge << std::endl;

    ret = BinarySearch(data, size, 8, ge, lt);
    assert(ret == 1);
    std::cout << ge << std::endl;
    memmove(data + ge + 1, data + ge, (size - ge) * sizeof(int));
    data[ge] = 8;
    ++size;

    for (int i=0; i < size; ++i) {
        std::cout << data[i] << ",";
    }
    std::cout << std::endl;

    ret = BinarySearch(data, size, 28, ge, lt);
    assert(ret == -1);
    std::cout << lt << std::endl;
    memmove(data + lt + 1, data + lt + 2, (size -lt + 1) * sizeof(int));
    data[lt + 1] = 28;
    ++size;

    for (int i=0; i < size; ++i) {
        std::cout << data[i] << ",";
    }
    std::cout << std::endl;
#endif

    key = 0;
    ret = TemplateBinarySearch(data, size, IntCompare, &key, ge, lt);
    assert(ret == 0);
    std::cout << ret << "," << lt << "," << ge << std::endl;

    key = 8;
    ret = TemplateBinarySearch(data, size, IntCompare, &key, ge, lt);
    std::cout <<ret << "," << lt << "," << ge << std::endl;

    key = 28;
    ret = TemplateBinarySearch(data, size, IntCompare, &key, ge, lt);
    std::cout <<ret << "," << lt << "," << ge << std::endl;

    return 0;
}
