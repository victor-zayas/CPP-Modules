#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

#include <iostream>
#include "AMateria.hpp"

class IMateriaSource {
private:
	std::string	_type;
	AMateria	*slot;

public:
	IMateriaSource(std::string type);
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria *createMateria(std::string const &type) = 0;
	virtual ~IMateriaSource() {}
};

#endif
