#include "Serializer.hpp"

int	main() {

	Data test;
	Data *ptr;

	uintptr_t uptr;
	test.i = 42;

	std::cout << "Test: " << &test << std::endl;
	std::cout << "Ptr: " << ptr << std::endl;

    std::cout << std::endl;
	uptr = Serializer::serialize(&test);
	std::cout << "Ptr serrialize: " << ptr << std::endl;
	ptr = Serializer::deserialize(uptr);
	std::cout << "Ptr deserialize: " << ptr << std::endl;

    std::cout << std::endl;
	std::cout << "Ptr->i: " << ptr->i << std::endl;
	std::cout << "Test: " << &test << std::endl;
}