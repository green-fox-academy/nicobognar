#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that reads a number form the standard input,

    float inputNumber;
    std::cout << "Please enter a number: " << std::endl;
    std::cin >> inputNumber;
    // If the number is zero or smaller it should print: Not enough
    if(inputNumber <= 0){
        std::cout << "Not enough"  << std::endl;
    } else if(inputNumber == 1){
        std::cout << "One"  << std::endl;
    } else if(inputNumber == 2){
        std::cout << "Two"  << std::endl;
    } else if(inputNumber > 2){
        std::cout << "A lot"  << std::endl;
    }
    // If the number is one it should print: One

    // If the number is two it should print: Two
    // If the number is more than two it should print: A lot

    return 0;
}