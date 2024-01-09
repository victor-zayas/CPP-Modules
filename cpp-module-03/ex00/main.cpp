#include "ClapTrap.hpp"

int main(void) {
    ClapTrap    JoaquinJavier("Jokin");
    ClapTrap    LuisMiguel("Luis");
    ClapTrap    Nameless = ClapTrap();
    ClapTrap    Copy = ClapTrap(Nameless);

    std::cout << std::endl;
    JoaquinJavier.attack("Luis");
    LuisMiguel.takeDamage(0);
    LuisMiguel.beRepaired(10);

    std::cout << std::endl;
    Nameless.attack("Copy");
    Copy.takeDamage(0);
    Copy.beRepaired((10));
    std::cout << std::endl;
}
