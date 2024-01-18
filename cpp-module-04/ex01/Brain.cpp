#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
	std::string makelele;
	std::ostringstream	conversion;
	for (int i = 0; i < 100; i++) {
		conversion << i;
		makelele = conversion.str();
		this->_ideas[i] = "Idea " + makelele;
	}
}

Brain::Brain(const Brain &copy) {
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++) {
		this->_ideas[i] = copy._ideas[i];
	}
}

Brain	&Brain::operator=(const Brain &other) {
	std::cout << "Brain operator constructor called" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			this->_ideas[i] = other._ideas[i];
		}
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

void	Brain::setIdeas(int i, std::string idea) {
	this->_ideas[i] = idea;
}

std::string	Brain::getIdeas(int i) {
	return this->_ideas[i];
}
