
#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <cstring>
#include "weapon.hpp"

class HumanB {
    private:
        std::string _name;
        Weapon *weapon;

    public:
        // HumanB();
        HumanB(std::string name);
        HumanB(const HumanB &copy);
        HumanB &operator=(const HumanB &other);
        ~HumanB();

        void    setName(std::string);
        const std::string getName();

        void    setWeapon(const std::string weapon);
        void    attack();

};

#endif