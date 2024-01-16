#ifndef FIXED_HPP
#define FIXED_HPP

#include<iostream>

class	Fixed {
private:

    int _fix;
    static const int _bit = 8;

public:

    Fixed();
    Fixed(const int num);
    Fixed(const float num);
    Fixed(const Fixed &copy);
    Fixed   &operator=(const Fixed &other);
    ~Fixed();

    // comparison operators
    bool    operator>(const Fixed &other) const;
    bool    operator<(const Fixed &other) const;
    bool    operator>=(const Fixed &other) const;
    bool    operator<=(const Fixed &other) const;
    bool    operator==(const Fixed &other) const;
    bool    operator!=(const Fixed &other) const;

    // arithmetic operators
    Fixed   operator-(const Fixed &other);
    Fixed   operator+(const Fixed &other);
    Fixed   operator*(const Fixed &other);
    Fixed   operator/(const Fixed &other);

    // increment/decrement operators
    Fixed   operator++();
    Fixed   operator++(int);
    Fixed   operator--();
    Fixed   operator--(int);

    static  Fixed   &min(Fixed &a, Fixed &b);
    static  Fixed   &min(const Fixed &a, const Fixed &b);
    static  Fixed   &max(Fixed &a, Fixed &b);
    static  Fixed   &max(const Fixed &a, const Fixed &b);

    void   setRawBits(const int raw);
    int    getRawBits(void) const;

    int toInt(void) const;
    float toFloat(void) const;

};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif

