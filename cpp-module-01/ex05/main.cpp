
#include "harl.hpp"

int main(int argc, char **argv) {
    Harl	harl;

    std::cout << "--- DEBUG LEVEL ---" << std::endl;
    harl.complain("DEBUG");
    std::cout << "--- INFO LEVEL ---" << std::endl;
    harl.complain("INFO");
    std::cout << "--- WARNING LEVEL ---" << std::endl;
    harl.complain("WARNING");
    std::cout << "--- ERROR LEVEL ---" << std::endl;
    harl.complain("ERROR");
    std::cout << "--- UNDEFINED ---" << std::endl;
    harl.complain("KAREN");
    return (0);
}