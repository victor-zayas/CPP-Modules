
#include<iostream>

int main(void) {
    // string
    std::string brain = "HI THIS IS BRAIN";
    // pointer
    std::string *ptr = &brain;
    // reference
    std::string &ref = brain;

    std::cout << "<----Memory address---->" << std::endl;

    std::cout << "String: " << &brain << std::endl;
    std::cout << "Pointer: " << ptr << std::endl;
    std::cout << "Reference: " << &ref << std::endl;

    std::cout << "<----Content---->" << std::endl;

    std::cout << "String: " << brain << std::endl;
    std::cout << "Pointer: " << *ptr << std::endl;
    std::cout << "Reference: " << ref << std::endl;
}
