
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include<iostream>

class	Zombie {
private:

	std::string	_name;
	void	announce(void);

public:

	Zombie() : _name("") {}

    Zombie(const Zombie &copy) {
        _name = copy._name;
    }

    Zombie &operator=(const Zombie &other) {
        if (this != &other) {
        _name = other._name;
        }
        return *this;
    }

    ~Zombie() {
		std::cout << "Zombie: " << getName() << " explodes" << std::endl;
	}

	void	setName(std::string name);
	std::string	getName();

	Zombie	*newZombie(std::string name);
	void	randomChump(std::string name);

};

#endif
