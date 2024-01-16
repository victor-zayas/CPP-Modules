#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <iostream>

class ICharacter {
private:
	std::string	_name;

public :
	ICharacter();
	ICharacter(std::string name);
	ICharacter(const ICharacter &copy);
	ICharacter &operator=(const ICharacter &other);

	void	setName(std::string name);
	std::string	getName();

};

#endif