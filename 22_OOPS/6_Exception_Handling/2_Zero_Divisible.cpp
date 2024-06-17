#include <iostream>
#include <stdexcept>

int main() {
    int a;
    int b;

    std::cout << "Enter a: ";
    std::cin >> a;

    std::cout << "Enter b: ";
    std::cin >> b;

    try {
        if (b == 0) {
            throw std::runtime_error("Division by zero is not allowed");
        }

        int c = a / b;
        std::cout << "The result is " << c << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}