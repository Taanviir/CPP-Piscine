#include "Span.hpp"

Span::Span() {}

Span::Span(Span const& copy): _capacity(copy._capacity) {
    for (size_t i = 0; i < copy._numbers.size(); i++)
        this->_numbers.push_back(copy._numbers[i]);
    *this = copy;
}

Span::~Span() {}

Span& Span::operator=(Span const& copy) {
    _capacity = copy._capacity;
    for (size_t i = 0; i < copy._numbers.size(); i++)
        _numbers.push_back(copy._numbers[i]);
    return *this;
}

Span::Span(unsigned int N): _capacity(N) {}

void Span::addNumber(int number) {
    if (_numbers.size() >= _capacity)
        throw std::runtime_error("Array is full.");
    _numbers.push_back(number);
}

int Span::shortestSpan(void) {
    if (_capacity < 2)
        throw std::runtime_error("Not enough numbers for span calculation.");

    std::vector<int> sortedArray(_numbers);
    std::sort(sortedArray.begin(), sortedArray.end());

    int shortest = sortedArray[1] - sortedArray[0];
    for (size_t i = 2; i < sortedArray.size(); i++) {
        int difference = sortedArray[i] - sortedArray[i - 1];
        if (difference < shortest)
            shortest = difference;
    }

    return shortest;
}

int Span::longestSpan(void) {
    if (_capacity < 2)
        throw std::runtime_error("Not enough numbers for span calculation.");

    std::vector<int> sortedArray(_numbers);
    std::sort(sortedArray.begin(), sortedArray.end());

    return (sortedArray[_capacity - 1] - sortedArray[0]);
}

void Span::addManyNumbers(std::vector<int>& newArray) {
    if (_numbers.size() + newArray.size() > _capacity)
        throw std::runtime_error("Too many numbers added.");
    _numbers.insert(_numbers.end(), newArray.begin(), newArray.end());
}
