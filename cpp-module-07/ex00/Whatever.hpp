#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template<typename T>
void    swap(T &a, T &b) {
    T   aux;

    aux = a;
    a = b;
    b = aux;
}

template<typename T>
T   min(T a, T b) {
    return b < a ? b : a;
}

template<typename T>
T   max(T a, T b) {
    return b > a ? b : a;
}

#endif
