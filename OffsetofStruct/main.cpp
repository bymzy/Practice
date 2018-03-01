

#include <stddef.h>
#include <iostream>

typedef struct TestStruct {
    int a;
    int b;
    int c;
}TestStruct;

int main() {
    std::cout << "size of struct " << sizeof(TestStruct) << std::endl
            << "offset of c " << (size_t) & (((TestStruct*)0)->c) << std::endl
           << "offset of c " << offsetof(TestStruct, c) << std::endl;

    TestStruct * ptr = new TestStruct;
    int * pc = &ptr->c;

    /* 类似于linux中的 container_of */
    std::cout << (void *)ptr << std::endl
             << (void *)((char *)pc - offsetof(TestStruct, c)) << std::endl;
}

