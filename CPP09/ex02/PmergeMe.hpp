#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <list>
# include <iostream>
# include <ctime>
# include <algorithm>

class PmergeMe {
public:
    PmergeMe(int* arr, int size);
    ~PmergeMe();

    void sort(void);

private:
    std::vector<int> _array;
    std::list<int> _list;
    int _size;

    void _sortArray(void);
    void _sortList(void);

    PmergeMe();
    PmergeMe(PmergeMe const& copy);
    PmergeMe& operator=(PmergeMe const& copy);
};

#endif // PMERGEME_HPP
