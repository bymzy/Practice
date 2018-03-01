

#include <stddef.h>
#include <iostream>

struct s1{
    int a;
    int b;
};

#pragma pack(8)
struct s2{
    char c;
    int a;
    double b;
};

struct s3 {
    char b[10];
    double a;
};

#pragma unpack
struct s4 {
    char c;
    int a;
    double b;
};

/* 结构体的内存对齐，变量的起始地址偏移为 n * min(sizeof(type), pragma pack size) */

union u1 {
    char a[14];
    int b;
};

union u2 {
    char a[17];
    double b;
};

/* union 的对齐简直不懂 */

#pragma pack(1)

struct s5 {
    char a;
    int b;
};

#pragma unpack
int main() {
    std::cout << "sizeof s1 " << sizeof(s1) << std::endl
              << "sizeof s2 " << sizeof(s2) << std::endl
              << "sizeof s3 " << sizeof(s3) << std::endl
              << "sizeof s4 " << sizeof(s4) << std::endl
              << "sizeof s5 " << sizeof(s5) << std::endl
              << "sizeof u1 " << sizeof(u1) << std::endl
              << "sizeof u2 " << sizeof(u2) << std::endl
              << std::endl;
    return 0;
}

