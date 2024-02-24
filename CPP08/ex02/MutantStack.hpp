#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

// TODO don't inherit from std::stack as std::stack destructor is not virtual

template < typename T >
class MutantStack: public std::stack<T> {
public:
    typedef typename std::stack<T>::container_type::iterator iterator;

    MutantStack() {}
    MutantStack(MutantStack const & src) { *this = src; }
    ~MutantStack() {}
    MutantStack & operator=(MutantStack const & src) {
        if (this != &src) {
            std::stack<T>::operator=(src);
        }
        return *this;
    }

    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }

};

#endif // MUTANTSTACK_HPP
