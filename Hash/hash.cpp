

#include <limits.h>
#include <iostream>

unsigned int BKDRHash(const char *str)
{
    unsigned int seed = 131;
    unsigned int hash = 0;

    while (*str) {
        hash = hash * seed + (*str++);
    }

    return hash & (0x7FFFFFFF);
}

int main()
{
    std::string s;
    while (std::getline(std::cin, s)) {
        std::cout << BKDRHash(s.c_str()) << std::endl;
    }

    std::cout << -1 % 10 <<std::endl;

    int a = -1;
    unsigned int b = a;
    unsigned int c = 0xFFFFFFFF;
    int d = 0x80000000;

    std::cout << a << std::endl
        << b << std::endl
        << "max unsigned int, " << c << std::endl
        << "min unsigned int, " << 0x00000000 << std::endl
        << "max int, " << int(0x7FFFFFFF) << std::endl
        << " " << int(0xFFFFFFFF) << std::endl
        << "min int, " << d << std::endl;


    return 0;
}


