#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

void    ScalarConverter::convert(const std::string &literal) {
    try {
        char ch = toChar(literal);
        int i = toInt(literal);
        float f = toFloat(literal);
        double db = toDouble(literal);

        std::cout << "char: ";
        if (std::isprint(ch)) {
            std::cout << "'" << ch << "'" << std::endl;
        } else {
            std::cerr << "Non displayable" << std::endl;
        }

        std::cout << "Int: " << i << std::endl;

        if (!std::isnan(f)) {
             std::cout << "float: " << f << "f" << std::endl;
        } else {
            std::cerr << "float: nanf" << std::endl;
        }
        if (!std::isnan(db)) {
             std::cout << "double: " << db << std::endl;
        } else {
            std::cerr << "double: nan" << std::endl;
        }
    }
    catch (const std::exception &excep) {
        std::cerr << "Error: " << excep.what() << std::endl;
    }
}

char    ScalarConverter::toChar(const std::string &literal) {
    char ch;

    std::istringstream iss(literal);
    if (!(iss >> ch)) {
        throw std::invalid_argument("Invalid char");
    }
    return ch;
}

int    ScalarConverter::toInt(const std::string &literal) {
    int i;

    std::istringstream iss(literal);
    if (!(iss >> i)) {
        throw std::invalid_argument("Invalid int");
    }
    return i;
}


float    ScalarConverter::toFloat(const std::string &literal) {
    float f;

    std::istringstream iss(literal);
    if (!(iss >> f)) {
        throw std::invalid_argument("Invalid float");
    }
    return f;
}

double    ScalarConverter::toDouble(const std::string &literal) {
    double db;

    std::istringstream iss(literal);
    if (!(iss >> db)) {
        throw std::invalid_argument("Invalid double");
    }
    return db;
}
