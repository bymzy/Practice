//
// Created by bymzy@outlook.com on 2018/3/5.
//

#include <iostream>

#define FLAG_read       0x00000001
#define FLAG_write      0x00000002
#define FLAG_exec       0x00000004
#define FLAG_valid      (FLAG_read|FLAG_write|FLAG_exec)

#define DATA_read       0x00000100
#define DATA_write      0x00000200
#define DATA_delete     0x00000400
#define DATA_valid      (DATA_read|DATA_write|DATA_delete)

int main(int argc, char *argv[])
{
    int flag = FLAG_valid;

    /* 判断某个flag是否被设置 */
    if ((flag & FLAG_read) == FLAG_read) {
        std::cout << "read flag set!!!" << std::endl;
    }

    /* 判断是否有除valid外的bit位被设置 */
    flag |= 0x01000000;
    if (flag & ~FLAG_valid) {
       std::cout << "invalid flag" << std::endl;
    }

    /* 判断有某个flag，但是没有其他flag */
    flag = FLAG_read;
    if ((flag & (FLAG_read | FLAG_write)) == FLAG_read) {
        std::cout << "only flag read is set!" << std::endl;
    }

    return 0;
}

