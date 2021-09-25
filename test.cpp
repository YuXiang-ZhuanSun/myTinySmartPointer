#include "my_tiny_smart_pointer.h"
#include <iostream>
int main()
{
    //class my_unique_ptr test
    auto a(make_unique<int>(10));
    auto b=std::move(a);
    std::cout<<*b<<std::endl;
    std::cout<<a.isNull()<<std::endl;
    std::cout<<b.isNull()<<std::endl;
    return 0;
}