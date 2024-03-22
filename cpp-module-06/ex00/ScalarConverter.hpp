#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iomanip>
# include <iostream>
# include <cstdlib>
# include <string>

class	ScalarConverter {
private:
	ScalarConverter();
	ScalarConverter(ScalarConverter const &copy);
	ScalarConverter &operator=(ScalarConverter const &other);
	static void			toChar(std::string input);
	static void			toInt(std::string input);
	static void			toFloat(std::string input);
	static void			toDouble(std::string input);

public:
	~ScalarConverter();

	static void			convert(std::string input);

	class NonDisplayable : public std::exception {
		public:
			virtual const char* what() const throw() {
				return ("Non displayable");
			}
	};

	class Impossible : public std::exception {
		public:
			virtual const char* what() const throw() {
				return ("Impossible");
			}
	};
};

#endif