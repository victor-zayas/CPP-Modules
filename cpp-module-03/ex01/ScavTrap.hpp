# ifndef SCAVTRAV_HPP
# define SCAVTRAV_HPP

#include<iostream>
#include"ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:

    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap &copy);
    ScavTrap &operator=(const ScavTrap &other);
    ~ScavTrap();

    void    guardGate();
};

# endif