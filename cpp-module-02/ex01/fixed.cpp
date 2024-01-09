#include "fixed.hpp"

Fixed::Fixed(): _fix(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num): _fix(num << _bit) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num): _fix(static_cast<int>(num * (1 << _bit))) {
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) {
    _fix = copy._fix;
    std::cout << "Copy constructor called" << std::endl;
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
    return static_cast<float>(_fix) / (1 << _bit);
}

int Fixed::toInt() const {
    return _fix >> _bit;
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