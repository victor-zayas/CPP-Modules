
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include "contact.hpp"

class PhoneBook {
public:
    Contact contacts[8];

    PhoneBook() {
        for(int i = 0; i < 8; i++){
            contacts[i] = Contact();
        }
    }
    PhoneBook(const PhoneBook &copy) {
        for (int i = 0; i < 8; i++) {
            contacts[i] = copy.contacts[i];
        }
    }
    PhoneBook &operator=(const PhoneBook &other){
        if (this != &other){
            for (int i = 0; i < 8; i++) {
                contacts[i] = other.contacts[i];
            }
        }
        return *this;
    }
    ~PhoneBook(){}

    void    createContact(void);
    void	searchContact(void);
};

#endif
