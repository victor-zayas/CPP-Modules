#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <stdexcept>

template<typename T>
typename T::iterator    easyfind(T &container, int val) {
    typename T::iterator i;
    for (i = container.begin(); i != container.end(); i++) {
        if (*i == val)
            return i;
    }
    return container.end(); // Return iterator to end if value not found
}

#endif
