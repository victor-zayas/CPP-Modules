
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include<iostream>

class	Zombie {
private:

	std::string	_name;

public:

	Zombie();
    Zombie(const Zombie &copy);
    Zombie &operator=(const Zombie &other);
    ~Zombie();

	void	setName(std::string name);
	std::string	getName();

	void	announce(void);

};

	Zombie	*newZombie(std::string name);
	void	randomChump(std::string name);
	Zombie *zombieHorde(int n, std::string name);

#endif
