#include "RPN.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " \"RPN expression\"" << std::endl;
        return 1;
    }

    std::string expression = argv[1];
    int result = evaluateRPN(expression);
    std::cout << result << std::endl;
}
