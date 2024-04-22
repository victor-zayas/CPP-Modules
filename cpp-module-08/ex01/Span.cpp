#include "Span.hpp"

Span::Span(): _vector(0), _size(0) {throw (std::exception());}

Span::Span(unsigned int val): _size(val) {
    this->_vector.reserve(this->_size);
    if (this->_size < 1)
        throw std::runtime_error("vector is not valid");
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

void    Span::addNumber(unsigned int nb) {
    if (this->_vector.size() == this->_size)
        throw std::runtime_error("vector is full");
    this->_vector.push_back(nb);
}


int	Span::shortestSpan(void) const {
	if (this->_vector.size() <= 1)
		throw std::runtime_error("cannot find Span");
	std::vector<int>	copy(this->_vector);
	std::sort(copy.begin(), copy.end());
	int span = copy[1] - copy[0];
	for (unsigned int i = 1; i < copy.size() - 1; i++) {
		int min = copy[i + 1] - copy[i];
		if (min < span)
			span = min;
	}
	return span;
}

int	Span::longestSpan(void) const {
	if (this->_vector.size() <= 1)
		throw std::runtime_error("cannot find Span");
	int min = *std::min_element(_vector.begin(), _vector.end());
	int max = *std::max_element(_vector.begin(), _vector.end());
	return max - min;
}

void	Span::addNumbers(void)
{
    std::srand(std::time(0));

    while (this->_size != 0)
    {
        int random_number = std::rand();
        this->_vector.push_back(random_number);
        this->_size--;
    }	
}