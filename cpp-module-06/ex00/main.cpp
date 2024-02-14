#include "ScalarConverter.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
        return 1;
    }

    ScalarConverter::convert(argv[1]);

    return 0;
}

/* int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
        return 1;
    }

    std::string input = argv[1];

    if (input == "nan" || input == "-inff" || input == "+inff" || input == "inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << input << std::endl;
        std::cout << "double: " << input << std::endl;
        return 0;
    }

    // Check if the input is a single character
    if (input.size() == 1) {
        std::cout << "char: '" << input[0] << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
        std::cout << "float: " << static_cast<float>(input[0]) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(input[0]) << std::endl;
        return 0;
    }

    ScalarConverter::convert(argv[1]);

    return 0;
} */
