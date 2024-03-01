#include "RPN.hpp"

int evaluateRPN(const std::string &expression) {
    std::stack<int> stack;
    std::istringstream expr(expression);
    std::string token;

    while (expr >> token) {
        if (isdigit(token[0])) {
            stack.push(std::atoi(token.c_str()));
        }
        else if (token.size() == 1 && ispunct(token[0])) {
            if (stack.size() < 2) {
                std::cerr << "Error" << std::endl;
                return 0;
            }
            int nb2 = stack.top();
            stack.pop();
            int nb1 = stack.top();
            stack.pop();
            switch (token[0]) {
                case '+':
                    stack.push(nb1 + nb2);
                    break;
                case '-':
                    stack.push(nb1 - nb2);
                    break;
                case '*':
                    stack.push(nb1 * nb2);
                    break;
                case '/':
                    stack.push(nb1 / nb2);
                    break;
                default:
                    std::cerr << "Error" << std::endl;
                    return 0;
            }
        }
        else {
            std::cerr << "Error" << std::endl;
            return 0;
        }
    }
    if (stack.size() != 1) {
        std::cerr << "Error" << std::endl;
        return 0;
    }
    return stack.top();
}
