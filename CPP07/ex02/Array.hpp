#ifndef ARRAY_HPP
# define ARRAY_HPP

template <class T>
class Array {
public:
    Array(): _size(0) { _array = new T; }
    ~Array() {
        if (_array)
            delete [] _array;
    }

    Array(Array const& copy): _size(copy._size) {
        _array = new T[_size];
        for (int i = 0; i < _size; i++)
            _array[i] = copy._array[i];
    };

    Array& operator=(Array const& copy) {
        if (this->_array)
            delete [] this->_array;
        this->_size = copy._size;
        this->_array = new T[_size];
        for (int i = 0; i < _size; i++)
            this->_array[i] = copy._array[i];
        return *this;
    };

    Array(int n): _size(n) {
        if (n < 0)
            throw InvalidIndex();
        _array = new T[n];
    }

    T& operator[](int n) {
        if (n < 0 || n >= _size || !_array)
            throw InvalidIndex();
        return _array[n];
    }

    int size() const { return _size; }

    class InvalidIndex: public std::exception {
        virtual const char* what() const throw() {
            return "Invalid index entered";
        }
    };

private:
    int _size;
    T* _array;
};

#endif // ARRAY_HPP
