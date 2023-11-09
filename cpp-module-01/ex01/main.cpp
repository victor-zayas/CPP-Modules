
#include"zombie.hpp"

int	main(void) {
	Zombie	zombie;

	std::cout << "A very big explosion can been saw from afar" << std::endl;
	std::cout << "the whole world is mutating..." << std::endl;
	
	// puntero a newZombie
	Zombie *pepeZombie = zombie.newZombie("pepe");

	// zombie horde
	Zombie *horde = zombie.zombieHorde(5, "illo");

	// randomChump
	zombie.randomChump("juan");

	delete pepeZombie;
}
