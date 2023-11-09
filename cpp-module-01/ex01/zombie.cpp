
#include"zombie.hpp"

void	Zombie::setName(std::string name) {
	this->_name = name;
}

std::string	Zombie::getName() {
	return _name;
}

void	Zombie::announce(void) {
	std::cout << this->_name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}
