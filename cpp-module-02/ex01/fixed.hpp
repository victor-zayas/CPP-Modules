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
    Fixed &operator=(const Fixed &other);
    ~Fixed();

    int    getRawBits(void) const;
    void   setRawBits(const int raw);

    float toFloat(void) const;
    int toInt(void) const;

};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif

