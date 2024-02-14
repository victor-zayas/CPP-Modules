#include <iostream>
#include "Array.hpp"

int main() {
    // Testing default constructor
    Array<int> arr1;
    std::cout << "arr1 size: " << arr1.size() << std::endl;

    // Testing parameterized constructor
    Array<int> arr2(5);
    std::cout << "arr2 size: " << arr2.size() << std::endl;

    // Testing copy constructor and operator=
    Array<int> arr3 = arr2;
    std::cout << "arr3 size: " << arr3.size() << std::endl;

    // Testing subscript operator and out of bounds exception
    try {
        std::cout << "arr2[10]: " << arr2[10] << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
