#ifndef PMERGEME_HPP
# define PMERGEME_HPP

class PmergeMe {
public:
    PmergeMe(int* arr, int size);
    ~PmergeMe();

private:
    PmergeMe();
    PmergeMe(PmergeMe const& copy);
    PmergeMe& operator=(PmergeMe const& copy);
};

#endif // PMERGEME_HPP
