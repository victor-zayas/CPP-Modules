#include "fixed.hpp"

Fixed::Fixed(): _fix(0) {}

Fixed::Fixed(const int num): _fix(num << _bit) {}

Fixed::Fixed(const float num): _fix(static_cast<int>(num * (1 << _bit))) {}

Fixed::Fixed(const Fixed &copy) {
    _fix = copy._fix;
}

Fixed &Fixed::operator=(const Fixed &other) {
    if (this != &other) {
        _fix = other._fix;
    }
    return *this;
}

Fixed::~Fixed() {}

// functions

int Fixed::getRawBits() const {
    return _fix;
}

void    Fixed::setRawBits(const int raw) {
    this->_fix = raw;
}

float Fixed::toFloat() const {
    return static_cast<float>(_fix) / (1 << _bit);
}

int Fixed::toInt() const {
    return _fix >> _bit;
}

// overload of the insertion («) operator
std::ostream& operator<<(std::ostream& num, const Fixed& fixed) {
    num << fixed.toFloat();
    return num;
}

// overload of the comparison operators
bool Fixed::operator>(const Fixed &other) const {
    return _fix > other._fix;
}
bool Fixed::operator<(const Fixed &other) const{
    return _fix < other._fix;
}
bool Fixed::operator>=(const Fixed &other) const{
    return _fix >= other._fix;
}
bool Fixed::operator<=(const Fixed &other) const{
    return _fix <= other._fix;
}
bool Fixed::operator==(const Fixed &other) const{
    return _fix == other._fix;
}
bool Fixed::operator!=(const Fixed &other) const{
    return _fix != other._fix;
}

// overload of the arithmetic operators
Fixed &Fixed::operator-(const Fixed &other) {
    this->setRawBits(this->_fix -= other.getRawBits());
    return *this;
}
Fixed &Fixed::operator+(const Fixed &other) {
    this->setRawBits(this->_fix += other.getRawBits());
    return *this;
}
Fixed &Fixed::operator*(const Fixed &other) {
    this->setRawBits(this->_fix * (other.getRawBits() >> this->_bit));
    return *this;
}
Fixed &Fixed::operator/(const Fixed &other) {
    this->setRawBits((this->_fix << this->_bit) / other.getRawBits());
    return *this;
}

// overload of the 4 increment/decrement operators
Fixed&  Fixed::operator++() {
    this->setRawBits(++this->_fix);
    return *this;
}
Fixed&  Fixed::operator++(int) {
    this->setRawBits(this->_fix + 1);
    return *this;
}
Fixed&  Fixed::operator--() {
    this->setRawBits(--this->_fix);
    return *this;
}
Fixed&  Fixed::operator--(int) {
    this->setRawBits(this->_fix - 1);
    return *this;
}

Fixed& Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}
const   Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}
const   Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}
