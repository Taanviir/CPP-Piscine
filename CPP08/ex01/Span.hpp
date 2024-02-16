#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>

class Span {
public:
    ~Span();
    Span(Span const& copy);
    Span &operator=(Span const& copy);

    Span(unsigned int N);

    void addNumber(int number);
    int shortestSpan(void);
    int longestSpan(void);
    void addManyNumbers(std::vector<int>& newArray);

private:
    std::vector<int> _numbers;
    unsigned int _capacity;

    Span();
};

#endif // SPAN_HPP
