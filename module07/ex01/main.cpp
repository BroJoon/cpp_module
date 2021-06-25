#include "iter.hpp"
#include <iostream>

template <typename T>
void printArr(T const &t)
{
    std::cout << t << std::endl;
}

int main(void)
{
    int iarr[5] = {1, 2, 3, 4, 5};
    iter(iarr, 5, printArr);
    char carr[3] = {'a', 'b', 'c'};
    iter(carr, 3, printArr);
    std::string sarr[2] = {"hello", "hi"};
    iter(sarr, 2, printArr);
    float farr[5] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    iter(farr, 5, printArr);
    double darr[3] = {1.1111, 2.2222, 3.3333};
    iter(darr, 2, printArr); 
}