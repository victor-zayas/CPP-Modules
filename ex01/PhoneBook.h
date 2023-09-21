
#ifndef PHONBOOK_H
#define PHONBOOK_H
#endif

#include<iostream>
#include "contact.hpp"

class PhonBook {
public:
    Contact contacts[8];

    PhonBook(){
        for(int i = 0; i < 8; i++){
            contacts[i] = Contact();
        }
    }
    PhonBook(const PhonBook &copy) {
        for (int i = 0; i < 8; i++) {
            contacts[i] = copy.contacts[i];
        }
    }
    PhonBook &operator=(const PhonBook &other){
        if (this != &other){
            for (int i = 0; i < 8; i++) {
                contacts[i] = other.contacts[i];
            }
        }
        return *this;
    }
};