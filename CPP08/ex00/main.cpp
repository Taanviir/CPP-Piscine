#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main() {
    std::cout << "Vector" << std::endl;
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    std::cout << easyfind(vec, 3) << std::endl;
    try {
        std::cout << easyfind(vec, 6) << std::endl;
    } catch (std::exception &e) {
        std::cout << "Number not found" << std::endl;
    }

    std::cout << "Queue" << std::endl;
    std::deque<int> deq;
    deq.push_back(1);
    deq.push_back(2);
    deq.push_back(3);
    std::cout << easyfind(deq, 2) << std::endl;

    std::cout << "Linked List" << std::endl;
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);
    std::cout << easyfind(lst, 3) << std::endl;
    try {
        std::cout << easyfind(lst, 6) << std::endl;
    } catch (std::exception &e) {
        std::cout << "Number not found" << std::endl;
    }

    return 0;
}
