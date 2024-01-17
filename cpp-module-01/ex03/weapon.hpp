
#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {
    private:
        std::string _type;

    public:

        Weapon(const std::string weaponType);
        Weapon(const Weapon &copy);
        Weapon &operator=(const Weapon &other);
        ~Weapon();

        void    setType(std::string newType);
        const std::string getType();
};

#endif
