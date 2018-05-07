

#include <stdio.h>
#include <string.h>

//aa bb cc==> aa%20bb%20cc
void FillBlankspace(char *data)
{
    char *index = data;
    int blankSpaceCount = 0;
    for (;*index != '\0'; ++index) {
        if (*index == ' ') {
            ++blankSpaceCount;
        }
    }

    if (blankSpaceCount == 0) {
        return;
    }

    int oldLength = strlen(data);
    int newLength = oldLength + blankSpaceCount * 2;

    data[newLength] = 0;

    while (oldLength > 0 && newLength > oldLength) {
        if (data[oldLength] == ' ') {
            data[newLength--] = '0';
            data[newLength--] = '2';
            data[newLength--] = '%';
        } else {
            data[newLength--] = data[oldLength];
        }
        --oldLength;
    }

    return;
}

int main()
{
    char data[100];
    memset(data, 0, 100);
    strcpy(data, "aa bb cc dd  ");
    printf("%s\n", data);

    FillBlankspace(data);
    printf("%s\n", data);
}


