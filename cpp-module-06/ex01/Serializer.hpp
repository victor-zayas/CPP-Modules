#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

struct Data {
	int	i;
};

class Serializer {
private:
    Serializer();
    Serializer(const Serializer &copy);
    Serializer &operator=(const Serializer &other);

public:
    ~Serializer();

    static  uintptr_t   serialize(Data *ptr);
    static    Data    *deserialize(uintptr_t raw);
};

#endif