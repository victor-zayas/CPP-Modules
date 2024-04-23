#include "Array.hpp"

#define MAX_VAL 4

int main(int, char	**)
{
	Array<int> numbers((unsigned int)MAX_VAL);
	int	*test = new int[MAX_VAL];

	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++) {
		const int value = rand();
		numbers[i] = value;
		test[i] = value;
	}
	
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}
	
	for (int i = 0; i < MAX_VAL; i++) {
		if (test[i] != numbers[i])
		{
			std::cerr << "Didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	
	std::cout << std::endl;
	try {
		std::cout << "Invalid array size" << std::endl;
		numbers[-2] = 0;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	try {
		numbers[MAX_VAL] = 0;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	
	std::cout << std::endl;
	try {
		for (int i = 0; i < MAX_VAL; i++) {
			numbers[i] = rand();
		}
		std::cout << "Array of size " << MAX_VAL << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	
	std::cout << std::endl;
	try {
		Array<int> n(0);
		std::cout << "Array of empty size" << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "Array: " << numbers << std::endl << std::endl;

	delete [] test;
}
