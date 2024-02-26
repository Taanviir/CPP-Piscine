#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template <typename Type>
class MutantStack: public std::stack<Type> {
public:
    typedef typename std::stack<Type>::container_type::iterator iterator;

    MutantStack() {}
    MutantStack(MutantStack const& src) { *this = src; }
    ~MutantStack() {}
    MutantStack& operator=(MutantStack const& src) {
        std::stack<Type>::operator=(src);
        return *this;
    }

    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }

};

#endif // MUTANTSTACK_HPP
