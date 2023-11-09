
#include"zombie.hpp"

void	Zombie::randomChump(std::string name) {
	Zombie *newZombie = new Zombie();
	newZombie->setName(name);
	newZombie->announce();
}
