#include "Iter.hpp"
#include <iostream>

template<typename T>
void printElement(const T &element) {
    std::cout << element << " ";
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    char charArray[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};

    std::cout << std::endl;
    std::cout << "Printing intArray elements: ";
    iter(intArray, 3, printElement);
    std::cout << std::endl << std::endl;

    std::cout << "Printing charArray elements: ";
    iter(charArray, 5, printElement);
    std::cout << std::endl << std::endl;
}
