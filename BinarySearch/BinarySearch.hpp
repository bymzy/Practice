//
// Created by bymzy@outlook.com on 2018/3/3.
//

#ifndef PRACTICE_BINARYSEARCH_HPP
#define PRACTICE_BINARYSEARCH_HPP

/* data is in ascending order */
int BinarySearch(int *data, int size, int key, int& ge, int &lt) {
    int low = 0;
    int high = size - 1;
    int mid = 0;
    int ret = 0;

    while (low <= high) {
        //mid = (low + high) >> 1;
        mid = low + ((high - low) >> 1);
        if (data[mid] > key) {
            high = mid - 1;
            ge = mid;
            lt = ge - 1;
            ret = 1;
        } else if (data[mid] < key) {
            low = mid + 1;
            lt = mid;
            ge = lt + 1;
            ret = -1;
        } else{
            ret = 0;
            ge = mid;
            lt = ge - 1;
            break;
        }
    }

    return ret;
}

template<typename T, typename  CmpFunc>
int TemplateBinarySearch(T *data, int size, CmpFunc cmp, T *key, int &ge, int &lt)
{
    int low = 0;
    int high = size - 1;
    int mid = 0;
    int ret = 0;

    while (low <= high) {
        mid = low + ((high - low) >> 1);
        ret = cmp(data + mid, key);
        if (ret > 0) {
            high = mid - 1;
            ge = mid;
            lt = ge - 1;
        } else if (ret < 0) {
            low = mid + 1;
            lt = mid;
            ge = lt + 1;
        } else {
            ge = mid;
            lt = ge - 1;
            break;
        }

    }

    return ret;
}

#endif //PRACTICE_BINARYSEARCH_HPP
