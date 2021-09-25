#include "my_tiny_smart_pointer.h"
#include <iostream>
auto p_2_int(const int & x)
{
    auto tem(make_unique<int>(x));
    return tem;
}
int main()
{
    //class my_unique_ptr test
    auto a(make_unique<int>(10));
    auto b=std::move(a);
    std::cout<<*b<<std::endl;
    std::cout<<a.isNull()<<std::endl;
    std::cout<<b.isNull()<<std::endl;
    auto c = p_2_int(99);
    std::cout<<*c<<std::endl;
    return 0;
}
