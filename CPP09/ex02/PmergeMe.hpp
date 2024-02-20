#ifndef PMERGEME_HPP
# define PMERGEME_HPP

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(PmergeMe const& copy);
    ~PmergeMe();
    PmergeMe& operator=(PmergeMe const& copy);

private:
};

#endif // PMERGEME_HPP
