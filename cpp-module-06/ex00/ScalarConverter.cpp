#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &copy) {
	*this = copy;
	return;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other) {
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

bool PseudoNb(const std::string str) {
	if (str == "nanf" || str == "-inff" || str == "+inff" || str == "nan" || str == "-inf" || str == "+inf" || str == "inf")
		return true;
	return false;
}

void	printPseudo(std::string input) {
	if (PseudoNb(input)) {
		std::cout << "char: " << "impossible" << "\n";
		std::cout << "int: " << "impossible" << "\n";
		std::cout << "float: " << ((input[input.size() - 1] == 'f') ? input : (input + 'f')) << std::endl;
		std::cout << "input: " << input << "\n";
	}
}

void	ScalarConverter::convert(std::string input) {
	if (!input.length()) {
		std::cout << "Empty input" << std::endl;
		return ;
	}
	if (PseudoNb(input)) {
		printPseudo(input);
		return ;
	}
	ScalarConverter::toChar(input);
	ScalarConverter::toInt(input);
	ScalarConverter::toFloat(input);
	ScalarConverter::toDouble(input);
}

void ScalarConverter::toChar(std::string input)
{
	std::cout << "char: ";
	try
	{
		char ch = static_cast<char>(input[0]);
        if (std::isprint(ch) && !std::isdigit(ch)) {
            std::cout << "'" << ch << "'" << std::endl;
        }
        else {
            std::cout << "Non displayable" << std::endl;
        }
	}
	catch (std::exception &e)
	{
		if (input.length() == 1 && std::isprint(input[0]))
			std::cout << "'" << static_cast<char>(input[0]) << "'" << std::endl;
		else
			std::cout << "impossible" << std::endl;
	}
}

void	ScalarConverter::toInt(std::string input) {
	std::cout << "int: ";
	try {
		std::cout << static_cast<int>(std::atoi(input.c_str())) << std::endl;
	}
	catch (std::exception &e) {
		if (input.length() == 1 && std::isprint(input[0]))
			std::cout << static_cast<int>(input[0]) << std::endl;
		else
			std::cout << "impossible" << std::endl;
	}
}

void ScalarConverter::toFloat(std::string input)
{
	std::cout << "float: ";
	try {
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(std::atof(input.c_str())) << "f" <<  std::endl;
	}
	catch (std::exception &e) {
		if (input.length() == 1 && std::isprint(input[0]))
			std::cout << std::fixed << std::setprecision(1) << static_cast<float>(input[0])<< "f" << std::endl;
		else
			std::cout << "impossible" << std::endl;
	}
}

void ScalarConverter::toDouble(std::string input)
{
	std::cout << "double: ";
	try {
		std::cout << std::fixed << std::setprecision(1) << static_cast<double>(std::atof(input.c_str())) << std::endl;
	}
	catch (std::exception &e) {
		if (input.length() == 1 && std::isprint(input[0]))
			std::cout << std::fixed << std::setprecision(1) << static_cast<double>(input[0]) << std::endl;
		else
			std::cout << "impossible" << std::endl;
	}
}