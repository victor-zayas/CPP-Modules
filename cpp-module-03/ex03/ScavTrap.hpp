# ifndef SCAVTRAV_HPP
# define SCAVTRAV_HPP

#include"ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
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
