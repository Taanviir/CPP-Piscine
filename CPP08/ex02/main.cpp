#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
    // int stack
    std::cout << "Int stack" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    std::cout << std::endl;

    // string stack
    std::cout << "String stack" << std::endl;
    MutantStack<std::string> mstack2;
    mstack2.push("Hello");
    mstack2.push("World");
    mstack2.push("!");

    MutantStack<std::string>::iterator it2 = mstack2.begin();
    MutantStack<std::string>::iterator ite2 = mstack2.end();
    while (it2 != ite2)
    {
        std::cout << *it2 << std::endl;
        ++it2;
    }
    std::cout << std::endl;

    // replace mutantstack with std::list
    std::cout << "Replace mutantstack with std::list" << std::endl;
    std::list<int> list;
    list.push_back(5);
    list.push_back(17);
    std::cout << list.back() << std::endl;
    list.pop_back();
    std::cout << list.size() << std::endl;
    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    //[...]
    list.push_back(0);
    std::list<int>::iterator it3 = list.begin();
    std::list<int>::iterator ite3 = list.end();
    ++it3;
    --it3;
    while (it3 != ite3)
    {
        std::cout << *it3 << std::endl;
        ++it3;
    }
    std::list<int> s2(list);

    return 0;
}
