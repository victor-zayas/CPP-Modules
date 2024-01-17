
#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <cstring>
#include "Weapon.hpp"

class HumanB {
    private:
        std::string _name;
        Weapon *weapon;

    public:
        HumanB(std::string name);
        HumanB(const HumanB &copy);
        HumanB &operator=(const HumanB &other);
        ~HumanB();

        void    setName(std::string);
        const std::string getName();

        void    setWeapon(Weapon &newWeapon);
        void    attack();

};

#endif
