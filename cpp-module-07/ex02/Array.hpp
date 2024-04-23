#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <iostream>
#include <cstdlib>

template <class T>
class Array {
	public:
		size_t	_size;
		T		*_array;
		
		Array<T>() {
			this->_array = new T[0]; this->_size = 0;
		};

		Array<T>(unsigned int size) {
			this->_array = new T[size]; this->_size = size;
		};

		Array<T>(const Array<T> &copy) {
			_size = copy._size; this->_array = new T[_size]; for (size_t index = 0; index < this->_size; index++) this->_array[index] = copy._array[index];
		};

		T	&operator=(const Array<T> &other) {
			this->_array = new T[this->_size]; for (size_t index; index < this->_size; index++) this->_array[index] = other._array[index]; return (*this);
		};

		T	&operator[](int index) const{
			if (index < 0) throw std::exception(); if (index > (int)this->_size) throw std::exception(); return(this->_array[index]);
		};
		
		size_t	size(void) const {
			return (this->_size);
		};
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const Array<T> &array) {
    os << "[";
    for (size_t i = 0; i < array.size(); ++i) {
        os << array[i];
        if (i < array.size() - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

#endif
