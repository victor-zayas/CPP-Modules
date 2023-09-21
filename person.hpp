
#ifndef PERSON_HPP
#define PERSON_HPP
#endif

#include "iostream"

class   Person{
private:
    std::string name;
    int age;
public:
    Person(std::string name, int age){
        this->name = name;
        this->age = age;
    }

    void showinfo(){
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};
