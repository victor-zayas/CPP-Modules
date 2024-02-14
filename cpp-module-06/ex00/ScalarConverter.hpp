#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <limits>
#include <cmath>

class ScalarConverter {
private:
    static char toChar(const std::string &literal);
    static int toInt(const std::string &literal);
    static float toFloat(const std::string &literal);
    static double toDouble(const std::string &literal);

public:
    ScalarConverter();
    ~ScalarConverter();

    static void convert(const std::string &literal);
};

#endif
