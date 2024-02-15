#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T& value1, T& value2) {
    T temp = value1;
    value1 = value2;
    value2 = temp;
}

template <typename T>
const T& min(const T& value1, const T& value2) {
    return value1 < value2 ? value1 : value2;
}

template <typename T>
const T& max(const T& value1, const T& value2) {
    return value1 > value2 ? value1 : value2;
}

#endif // WHATEVER_HPP
