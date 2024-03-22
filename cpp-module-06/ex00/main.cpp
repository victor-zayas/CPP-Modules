#include "ScalarConverter.hpp"

int  main(int argc, char **argv)
{
	if (argc != 2)
		std::cout << "Wrong number of arguments" << std::endl;
	try {
		ScalarConverter::convert(argv[1]);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}