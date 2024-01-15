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

    void	setName(std::string name);
    void	setEnergyPoints(uint amount);
    void	setHitPoints(uint amount);
    void	setAttackDamage(uint amount);

    std::string	getName() const;
    uint	getHitPoints() const;
    uint	getEnergyPoints() const;
    uint	getAttackDamage() const;

    void    attack(const std::string &target);
    void    takeDamage(unsigned int amount);
    void    beRepaired(unsigned int amount);

};

#endif