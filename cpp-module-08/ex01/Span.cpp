#include "Span.hpp"

Span::Span(): _size(0), _vector(0) {};

Span::Span(unsigned int val): _size(val) {
    this->_vector.reserve(this->_size);
    if (this->_size < 1)
        throw std::range_error("vector is not valid");
}

Span::Span(const Span &copy) {
    _size = copy._size;
    _vector.reserve(_size);
    std::vector<int> newVector = copy._vector;
	std::vector<int>::iterator	i = newVector.begin();
	while (i != copy._vector.end()) {
		this->_vector.push_back(*i);
		i++;
	}
}

const Span	&Span::operator=(const Span &copy) {
	this->_size = copy._size;
	this->_vector.reserve(_size);
	std::vector<int> newVector = copy._vector;
	std::vector<int>::iterator	i = newVector.begin();
	while (i != copy._vector.end()) {
		this->_vector.push_back(*i);
		i++;
	}
	return (*this);
}

Span::~Span() {}

void    Span::addNumber(unsigend int nb) {
    if (this->_vector.size() == _size)
        throw std::range_error("vector is full");
    this->_vector.push_back(nb);
}
