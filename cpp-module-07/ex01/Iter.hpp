#ifndef ITER_HPP
#define ITER_HPP

template<typename T>
void iter(T *array, int len, void(*func)(T const &)) {
    for (int i = 0; i < len; i++) {
        func(array[i]);
    }
}

#endif
