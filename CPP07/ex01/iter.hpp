#ifndef ITER_HPP
# define ITER_HPP

template<typename T, typename FuncType>
void iter(T* array, unsigned long arraySize, FuncType func) {
    for (unsigned long i = 0; i < arraySize; i++) {
        func(array[i]);
    }
}

#endif // ITER_HPP