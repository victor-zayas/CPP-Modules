
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>
#include <string>

class PhoneBook {
public:
    Contact contacts[8];

    PhoneBook();
    PhoneBook(const PhoneBook &copy);
    PhoneBook &operator=(const PhoneBook &other);
    ~PhoneBook();

    void    createContact(int &i);
    void	searchContact(void);
};

#endif
