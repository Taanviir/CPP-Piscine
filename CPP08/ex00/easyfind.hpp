#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iterator>
#include <algorithm>

template <typename T>
int easyfind(T& containter, int number) {
    typename T::iterator it = std::find(containter.begin(), containter.end(), number);
    if (it == containter.end()) {
        throw std::exception();
    }
    return *it;
}

#endif // EASYFIND_HPP
