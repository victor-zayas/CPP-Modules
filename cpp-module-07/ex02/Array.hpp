#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

/* template<class T>
class Array {
private:
    T   *_elements;
    unsigned int    _size;
public:
    Array();
    explicit Array(unsigned int n);
    Array(const Array<T> &copy);
    Array<T> &operator=(const Array<T> &other);
    ~Array();

    T   &operator[](unsigned int index);
    unsigned int size() const;
}; */

template <class T>
class Array {
public:
	size_t	_size;
	T		*_array;
	Array<T>() { this->_array = new T[0]; this->_size = 0; };
	Array<T>(unsigned int _numberOfElements) { this->_array = new T[_numberOfElements]; this->_size = _numberOfElements; };
	Array<T>(const Array<T> &_copy) { _size = _copy._size; this->_array = new T[_size]; for (size_t index = 0; index < this->_size; index++) this->_array[index] = _copy._array[index]; };
	T	&operator=(const Array<T> &_copy) { this->_array = new T[this->_size]; for (size_t index; index < this->_size; index++) this->_array[index] = _copy._array[index]; return (*this); };
	T	&operator[](int _reference) { if (_reference < 0) throw std::exception(); if (_reference > (int)this->_size) throw std::exception(); return(this->_array[_reference]); };
	size_t	size(void) const { return (this->_size); };
};

#endif
