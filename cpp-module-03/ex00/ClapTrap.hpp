#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include<iostream>

class	ClapTrap {
private:

    std::string	_name;
    uint _hitPoints;
    uint _energyPoints;
    uint _attackDamage;

public:

    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &copy);
    ClapTrap &operator=(const ClapTrap &other);
    ~ClapTrap();

    void setEnergyPoints(uint amount);
    void setHitPoints(uint amount);

    std::string	getName();
    uint	getHitPoints();
    uint	getEnergyPoints();
    uint	getAttackDamage();

    void    attack(const std::string &target);
    void    takeDamage(unsigned int amount);
    void    beRepaired(unsigned int amount);

};

#endif