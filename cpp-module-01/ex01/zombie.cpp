
#include"zombie.hpp"

Zombie::Zombie(): _name(""){}

Zombie::Zombie(const Zombie &copy) {
	_name = copy._name;
}

Zombie &Zombie::operator=(const Zombie &other) {
	if (this != &other) {
		_name = other._name;
	}
	return *this;
}

Zombie::~Zombie() {
	std::cout << "zombie explodes from starvation" << std::endl;
}

void	Zombie::setName(std::string name) {
	this->_name = name;
}

std::string	Zombie::getName() {
	return _name;
}

void	Zombie::announce(void) {
	std::cout << this->_name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}
