

#include <stdio.h>
#include <assert.h>


void Swap(int &left, int &right)
{
    int temp = left;
    left = right;
    right = temp;
}

int Partion(int *data, int startIndex, int endIndex)
{
    assert(endIndex >= startIndex &&
            startIndex >= 0 &&
            endIndex >= 0);

    if (startIndex == endIndex) {
        return startIndex;
    }

    int i = startIndex;
    int j = endIndex - 1;
    int x = data[endIndex];

    for (; i <=j; ++i) {
        if (data[i] < x) {
            data[endIndex] = data[i];
            break;
        }
    }

    for (; j >=i; --j) {
        if (data[j] > x) {
            break;
        }
    }

    data[i] = x;

    int pos = 0;
    if (i < j) {
        pos = Partion(data, i, j);
    } else {
        pos = i;
    }

    return pos;
}

/* endIndex included */
void QuickSort(int *data, int startIndex, int endIndex)
{
    int pos = Partion(data, startIndex, endIndex);

    if (pos > 0 && pos > startIndex) {
        QuickSort(data, startIndex, pos - 1);
    }

    if (pos < endIndex) {
        QuickSort(data, pos + 1, endIndex);
    }
}

int main()
{
    int a[] = {1, 12, 2 ,3 , 8, 5, 9, 7, 12};
    QuickSort(a, 0, 8);

    for (int i = 0; i < 9; ++i) {
        printf("%d\n", a[i]);
    }

    printf("===========\n");

    int b[] = {1};
    QuickSort(b, 0, 0);

    for (int i = 0; i < 1; ++i) {
        printf("%d\n", b[i]);
    }
}


