#include <iostream>
#include <exception>

int main() {
    try {
        int* p = new int[1000011111]; // Allocate a smaller amount of memory
        std::cout << "Memory allocated";
        delete[] p;
    } catch (const std::bad_alloc& e) {
        std::cout << "An error occurred: " << e.what() << std::endl;
    }

    return 0;
}