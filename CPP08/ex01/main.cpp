#include <iostream>
#include "Span.hpp"

int main(void)
{
    {
        std::cout << "Test 1: Normal test" << std::endl;
        Span sp = Span(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        std::cout << std::endl;
    }
    {
        std::cout << "Test 2: Add many numbers (Exception)" << std::endl;
        Span sp = Span(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        try {
            std::vector<int> v;
            v.push_back(1);
            v.push_back(2);
            v.push_back(3);
            sp.addManyNumbers(v);
        }
        catch (std::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
        std::cout << std::endl;
    }
    {
        std::cout << "Test 3: 10,000 Numbers" << std::endl;
        Span sp = Span(10000);

        for (int i = 0; i < 10000; i++)
            sp.addNumber(i);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        std::cout << std::endl;
    }
    {
        std::cout << "Test 4: 100,000 Numbers" << std::endl;
        Span sp = Span(100000);

        for (int i = 0; i < 50000; i++)
            sp.addNumber(i);

        std::vector<int> v;
        for (int i = 0; i < 50000; i++)
            v.push_back(i);
        sp.addManyNumbers(v);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        std::cout << std::endl;
    }
    {
        std::cout << "Test 5: 100,000 Numbers (Exception)" << std::endl;
        Span sp = Span(10000);

        for (int i = 0; i < 10000; i++)
            sp.addNumber(i);

        std::vector<int> v;
        for (int i = 0; i < 10000; i++)
            v.push_back(i);
        try {
            sp.addManyNumbers(v);
        }
        catch (std::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    return 0;
}
