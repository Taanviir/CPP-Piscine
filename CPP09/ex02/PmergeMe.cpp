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
    if (_array.size() == 0 || _list.size() == 0) {
        std::cout << "Error: Cannot sort empty containers" << std::endl;
        return;
    }

    {
        std::cout << "Before:  ";
        print(_array);

        clock_t start = clock();
        _sortArray();
        clock_t end = clock();

        std::cout << "After:   ";
        print(_array);

        double duration = (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1000000;
        std::cout << "Time to process a range of " << _array.size()
        << " elements with std::vector : " << duration << " us" << std::endl;
    }

    {
        clock_t start = clock();
        _sortList();
        clock_t end = clock();

        double duration = (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1000000;
        std::cout << "Time to process a range of " << _list.size()
        << " elements with std::list   : " << duration << " us" << std::endl;
    }
}

int binarySearch(const std::vector<int>& array, int target) {
    int low = 0;
    int high = array.size();

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (array[mid] < target)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

void PmergeMe::_sortArray(void) {
    std::vector< std::pair<int, int> > pairs;

    for (size_t i = 0; i < _array.size(); i += 2) {
        if (i + 1 < _array.size() && _array[i] < _array[i + 1])
            std::swap(_array[i], _array[i + 1]);
        std::pair<int, int> pairOfNums(_array[i], (i + 1 < _array.size() ? _array[i + 1] : -1));
        pairs.push_back(pairOfNums);
    }

    // bubble sort the pairs
    for (size_t i = 0; i < pairs.size() && pairs[i].second != -1; i++) {
        for (size_t j = i + 1; j < pairs.size() && pairs[j].second != -1; j++) {
            if (pairs[i].first > pairs[j].first)
                std::swap(pairs[i], pairs[j]);
        }
    }

    _array.clear();
    for (size_t i = 0; i < pairs.size() && pairs[i].second != -1; i++)
        _array.push_back(pairs[i].first);

    // insert the second element of the pair in the correct position using binary search
    for (size_t i = 0; i < pairs.size(); i++) {
        if (pairs[i].second == -1) {
            int index = binarySearch(_array, pairs[i].first);
            _array.insert(_array.begin() + index, pairs[i].first);
            break;
        }
        int index = binarySearch(_array, pairs[i].second);
        _array.insert(_array.begin() + index, pairs[i].second);
    }
}

int binarySearch(const std::list<int>& list, int target) {
    int low = 0;
    int high = list.size();

    while (low < high) {
        int mid = low + (high - low) / 2;

        std::list<int>::const_iterator itr = list.begin();
        std::advance(itr, mid);
        if (*itr < target)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

void PmergeMe::_sortList(void) {
    std::list< std::pair<int, int> > pairs;

    for (std::list<int>::iterator itr = _list.begin(); itr != _list.end(); itr++) {
        std::list<int>::iterator next = itr;
        next++;
        if (next != _list.end() && *itr < *next)
            std::swap(*itr, *next);
        std::pair<int, int> pairOfNums(*itr, (next != _list.end() ? *next : -1));
        pairs.push_back(pairOfNums);
        if (next != _list.end())
            itr++;
    }

    // bubble sort the pairs
    for (std::list< std::pair<int, int> >::iterator itr = pairs.begin(); itr != pairs.end() && itr->second != -1; itr++) {
        for (std::list< std::pair<int, int> >::iterator next = itr; next != pairs.end() && next->second != -1; next++) {
            if (itr->first > next->first)
                std::swap(*itr, *next);
        }
    }

    _list.clear();
    for (std::list< std::pair<int, int> >::iterator itr = pairs.begin(); itr != pairs.end() && itr->second != -1; itr++)
        _list.push_back(itr->first);

    // insert the second element of the pair in the correct position using binary search
    for (std::list< std::pair<int, int> >::const_iterator itr = pairs.begin(); itr != pairs.end(); itr++) {
        if (itr->second == -1) {
            int index = binarySearch(_list, itr->first);
            std::list<int>::iterator listItr = _list.begin();
            std::advance(listItr, index);
            _list.insert(listItr, itr->first);
            break;
        }
        int index = binarySearch(_list, itr->second);
        std::list<int>::iterator listItr = _list.begin();
        std::advance(listItr, index);
        _list.insert(listItr, itr->second);
    }
}
