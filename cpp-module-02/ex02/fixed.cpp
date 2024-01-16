#include "fixed.hpp"

Fixed::Fixed(): _fix(0) {}

Fixed::Fixed(const int num) {
    setRawBits(roundf(num * (1 <<_bit)));
}

Fixed::Fixed(const float num) {
    setRawBits(roundf(num * (1 << _bit)));
}

Fixed::Fixed(const Fixed &copy) {
    this->_fix = copy._fix;
}

Fixed &Fixed::operator=(const Fixed &other) {
    if (this != &other) {
        this->_fix = other._fix;
    }
    return *this;
}

Fixed::~Fixed() {}

// functions

int Fixed::getRawBits() const {
    return this->_fix;
}

void    Fixed::setRawBits(const int raw) {
    this->_fix = raw;
}

float Fixed::toFloat() const {
    return (roundf(_fix) / (1 << _bit));
}

int Fixed::toInt() const {
    return (_fix / (1 << _bit));
}

// overload of the insertion («) operator
std::ostream& operator<<(std::ostream& num, const Fixed& fixed) {
    num << fixed.toFloat();
    return num;
}

// overload of the comparison operators
bool Fixed::operator>(const Fixed &other) const {
    if (_fix > other._fix)
        return true;
    else
        return false;
}
bool Fixed::operator<(const Fixed &other) const{
    if (_fix < other._fix)
        return true;
    else
        return false;
}
bool Fixed::operator>=(const Fixed &other) const{
    if (_fix >= other._fix)
        return true;
    else
        return false;
}
bool Fixed::operator<=(const Fixed &other) const{
    if (_fix <= other._fix)
        return true;
    else
        return false;
}
bool Fixed::operator==(const Fixed &other) const{
    if (_fix == other._fix)
        return true;
    else
        return false;
}
bool Fixed::operator!=(const Fixed &other) const{
    if (_fix == other._fix)
        return false;
    else
        return true;
}

// overload of the arithmetic operators
Fixed   Fixed::operator-(const Fixed &other) {
    this->setRawBits(this->_fix -= other.getRawBits());
    return *this;
}
Fixed   Fixed::operator+(const Fixed &other) {
    this->setRawBits(this->_fix += other.getRawBits());
    return *this;
}
Fixed   Fixed::operator*(const Fixed &other) {
    this->setRawBits(this->_fix * (other.getRawBits() >> this->_bit));
    return *this;
}
Fixed   Fixed::operator/(const Fixed &other) {
    this->setRawBits((this->_fix << this->_bit) / other.getRawBits());
    return *this;
}

// overload of the 4 increment/decrement operators
Fixed   Fixed::operator++() {
    this->_fix += 1;
    return (*this);
}
Fixed   Fixed::operator++(int) {
    Fixed temp(*this);
    this->_fix += 1;
    return (temp);
}
Fixed   Fixed::operator--() {
    this->_fix -= 1;
    return (*this);
}
Fixed   Fixed::operator--(int) {
    Fixed temp(*this);
    this->_fix -= 1;
    return (temp);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b){
    if (a <= b)
        return a;
    else
        return b;
}

Fixed	&Fixed::max(Fixed &a, Fixed &b){
    if (a >= b)
        return a;
    else
        return b;
}

Fixed	&Fixed::min(const Fixed &a, const Fixed &b){
    if (a <= b)
        return ((Fixed &)a);
    else
        return ((Fixed &)b);
}

Fixed	&Fixed::max(const Fixed &a, const Fixed &b){
    if (a >= b)
        return ((Fixed &)a);
    else
        return ((Fixed &)b);
}
