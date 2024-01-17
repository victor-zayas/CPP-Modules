#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"

class ICharacter {
private:
	std::string	_name;
	std::string	slot[4];

public :
	ICharacter();
	ICharacter(std::string name);
	ICharacter(const ICharacter &copy);
	ICharacter &operator=(const ICharacter &other);
	virtual ~ICharacter();

	void	setName(std::string name);
	virtual std::string const &getName() const = 0;

	virtual void equip(AMateria *m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter &target) = 0;

};

#endif
