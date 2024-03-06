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

    void _sortArray(void);
    void _sortList(void);

    template <typename container>
    void print(container& con) {
        for (typename container::const_iterator itr = con.begin(); itr != con.end(); itr++)
            std::cout << *itr << " ";
        std::cout << std::endl;
    }

    template <typename container>
    int _binarySearch(container& con, int target) {
        int low = 0;
        int high = con.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            typename container::iterator itr = con.begin();
            std::advance(itr, mid);
            if (*itr == target)
                return mid;
            else if (*itr < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }

    PmergeMe();
    PmergeMe(PmergeMe const& copy);
    PmergeMe& operator=(PmergeMe const& copy);
};

#endif // PMERGEME_HPP
