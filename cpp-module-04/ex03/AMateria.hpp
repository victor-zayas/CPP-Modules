#ifndef	AMATERIA_H
#define AMATERIA_H

#include <iostream>
#include "ICharacter.hpp" // Include the header file for ICharacter

class AMateria
{
protected:
	std::string _type;

public:
	AMateria();
	AMateria(std::string const &type);
	AMateria(const	AMateria &copy);
	AMateria &operator=(const AMateria &other);
	~AMateria();
	
	void	setType(std::string type);
	std::string const &getType() const; //Returns the materia type
	
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};

#endif
