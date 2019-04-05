#include <iostream>

int main(int argc, char *args[]) {

    // Write a program that reads a number from the standard input,
    // Then prints "Odd" if the number is odd, or "Even" if it is even.
    int InputNumber;
    std::cout << "Please enter a number of your choosing: " << std::endl;
    std::cin >> InputNumber;
    if (InputNumber % 2 == 1) {
        std::cout << "Odd" << std::endl;
    } else {
        std::cout << "Even" << std::endl;
    }

    return 0;
}