
#ifndef CONTACT_HPP
#define CONTACT_HPP
#endif

#include "iostream"

class   Contact{
private:
    std::string name;
    std::string phone;

public:
    Contact(){
        name = "";
        phone = "";
    }
    Contact(std::string name, std::string phone){
        this->name = name;
        this->phone = phone;
    }
};