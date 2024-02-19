#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main() {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    std::cout << "TEST ONE" << std::endl;
    std::vector<int>::iterator found = easyfind(vec, 3);
    if (found != vec.end()) {
        std::cout << "Value found at index: " << std::distance(vec.begin(), found) << std::endl;
    } else {
        std::cerr << "Value not found in container" << std::endl;
    }

    std::cout << "TEST TWO" << std::endl;
    std::vector<int>::iterator notFound = easyfind(vec, 6);
    if (notFound != vec.end()) {
        std::cout << "Value found at index: " << std::distance(vec.begin(), notFound) << std::endl;
    } else {
        std::cerr << "Value not found in container" << std::endl;
    }
}
