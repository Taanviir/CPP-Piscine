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
    if (_size == 0) return;

    {
        clock_t start = clock();
        _sortArray();
        clock_t end = clock();

        double duration = (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1000;
        std::cout << "Time to process a range of " << _array.size()
        << " elements with std::vector: " << duration << " ms" << std::endl;
    }

    {
        clock_t start = clock();
        _sortArray();
        clock_t end = clock();

        double duration = (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1000;
        std::cout << "Time to process a range of " << _list.size()
        << " elements with std::list: " << duration << " ms" << std::endl;
    }
}

void PmergeMe::_sortArray(void) {
    // sort the vector
}

void PmergeMe::_sortList(void) {
    // sort the list
}
