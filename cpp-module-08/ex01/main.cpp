#include "Span.hpp"

int main() {
    std::cout << std::endl;
    std::cout << "Normal case: " << std::endl;
    try {
        Span span(5);
        span.addNumber(10);
        span.addNumber(5);
        span.addNumber(15);
        span.addNumber(20);
        span.addNumber(25);

        std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
        std::cout << "Longest span: " << span.longestSpan() << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Vector full case: " << std::endl;
     try {
        Span spin(1);
        spin.addNumber(10);
        spin.addNumber(5);

        std::cout << "Shortest span: " << spin.shortestSpan() << std::endl;
        std::cout << "Longest span: " << spin.longestSpan() << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Vector allredy short case: " << std::endl;
     try {
        Span spen(1);
        spen.addNumber(10);

        std::cout << "Shortest span: " << spen.shortestSpan() << std::endl;
        std::cout << "Longest span: " << spen.longestSpan() << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Add a range of numbers function: " << std::endl;
    try {
        Span spun(20);
        spun.addNumbers();

        std::cout << "Shortest span: " << spun.shortestSpan() << std::endl;
        std::cout << "Longest span: " << spun.longestSpan() << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
}
