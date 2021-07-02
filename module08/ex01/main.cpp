#include "span.hpp"

int main()
{
    Span sp = Span(5);
    sp.addNumber(5);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << "=====COPY TEST=====" << std::endl;
    Span copy = sp;
    std::cout << copy.shortestSpan() << std::endl;
    std::cout << copy.longestSpan() << std::endl;
    Span copy2(sp);
    std::cout << copy2.shortestSpan() << std::endl;
    std::cout << copy2.longestSpan() << std::endl;
    try
    {
        std::cout << "=====FULL ERROR=====" << std::endl;
        copy.addNumber(2);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        std::cout << "=====NOT ENOUGH NUMBER=====" << std::endl;
        Span er = Span(1);
        er.addNumber(42);
        std::cout << er.shortestSpan() << std::endl;
        std::cout << er.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        std::cout << "=====COPY ITERATOR=====" << std::endl;
        std::vector<int> vec;
        vec.push_back(10);
        vec.push_back(20);
        vec.push_back(30);
        vec.push_back(40);

        Span er2 = Span(4);
        //Span er2 = Span(3);
        er2.addNumberToit<std::vector<int>>(vec.begin(), vec.end());
        std::cout << er2.shortestSpan() << std::endl;
        std::cout << er2.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    Span test(10000);
    std::list<int> list;

    for (int i = 0; i < 10000; i++)
        list.push_back(i);
    test.addNumberToit<std::list<int>>(list.begin(), list.end());
    test.print_element();
    std::cout << test.shortestSpan() << std::endl;
    std::cout << test.longestSpan() << std::endl;
}