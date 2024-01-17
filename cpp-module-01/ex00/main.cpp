
#include "Zombie.hpp"

int	main(void) {

	std::cout << "A very big explosion can been saw from afar..." << std::endl;
	std::cout << "The whole world is mutating..." << std::endl;
	
	// pointer to newZombie
	 Zombie *pepeZombie = newZombie("pepe");

	// randomChump
	randomChump("juan");

	// use delete if you create newZombie in heap
	 delete pepeZombie;
}
