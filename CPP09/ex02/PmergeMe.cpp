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

void PmergeMe::sort(void) {
    clock_t start = clock();

    if (_array.size() == 0) return;
    else if (_array.size() > 1) {
    }
    clock_t end = clock();
    std::cout << "Time to process a range of " << _array.size() << " elements with std::vector: " << (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1000 << " ms" << std::endl;
}
