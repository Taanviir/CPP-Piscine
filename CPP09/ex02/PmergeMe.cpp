#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const& copy) {
    (void)copy;
}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(PmergeMe const& copy) {
    (void)copy;
    return *this;
}

PmergeMe::PmergeMe(int* arr, int size) {
    if (size == 0) return;

    // initialize the vector with the array
    for (int i = 0; i < size; i++)
        _array.push_back(arr[i]);

    // initialize the list with the array
    for (int i = 0; i < size; i++)
        _list.push_back(arr[i]);
}
