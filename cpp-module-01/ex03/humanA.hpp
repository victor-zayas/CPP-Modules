
#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <cstring>
#include "weapon.hpp"

class HumanA {
    private:
        std::string _name;
        Weapon &weapon;

    public:
        // HumanA();
        HumanA(std::string name, Weapon &weapon);
        HumanA(const HumanA &copy);
        HumanA &operator=(const HumanA &other);
        ~HumanA();

        void    setName(std::string);
        const std::string getName();

        void    attack();

};

#endif