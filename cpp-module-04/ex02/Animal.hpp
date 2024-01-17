# ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
    std::string _type;

public:
    Animal();
    Animal(const Animal &copy);
    Animal &operator=(const Animal &other);
    virtual ~Animal();

    void    setType(std::string newType);
    std::string getType() const;

    virtual void    makeSound() const = 0;
};

#endif
