
#include "Zombie.hpp"

// Create a new zombie name it and announce it, is store on stack
void	randomChump(std::string name) {
	Zombie newZombie;
	newZombie.setName(name);
	newZombie.announce();
}
