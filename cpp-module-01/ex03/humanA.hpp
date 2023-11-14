
#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "weapon.hpp"

class HumanA {
    private:
        std::string _name;
        Weapon weapon;

    public:
        HumanA(const std::string name, const Weapon weapon);
        HumanA(const std::string &copy);
        HumanA &operator=(const HumanA &other);
        ~HumanA();

        void    setName(std::string);
        const std::string getName();

        void    attack();

};

#endif