#include "fixed.hpp"

Fixed::Fixed(): _fix(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) {
    std::cout << "Int constructor called" << std::endl;
    setRawBits(roundf(num * (1 << _bit)));
}

Fixed::Fixed(const float num) {
    std::cout << "Float constructor called" << std::endl;
    setRawBits((roundf(num * (1 << _bit))));
}

Fixed::Fixed(const Fixed &copy) {
    std::cout << "Copy constructor called" << std::endl;
    _fix = copy._fix;
}

Fixed &Fixed::operator=(const Fixed &other) {
    if (this != &other) {
        _fix = other._fix;
    }
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat() const {
    return (roundf(_fix) / (1 << _bit));
}

int Fixed::toInt() const {
    return (_fix / (1 << _bit));
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return _fix;
}

void    Fixed::setRawBits(const int raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_fix = raw;
}

std::ostream& operator<<(std::ostream& num, const Fixed& fixed) {
    num << fixed.toFloat();
    return num;
}