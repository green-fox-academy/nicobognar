
#include <iostream>

int main(int argc, char *args[]) {

    // Create a program that prints a few operations on two numbers: 22 and 13
    double dnum1 = 22;
    double dnum2 = 13;
    int num1 = 22;
    int num2 = 13;
    // Print the result of 13 added to 22
    std::cout << num1 + num2 << std::endl;
    // Print the result of 13 substracted from 22
    std::cout << num1 - num2 << std::endl;
    // Print the result of 22 multiplied by 13
    std::cout << num2 * num1 << std::endl;
    // Print the result of 22 divided by 13 (as a decimal fraction)
    std::cout << dnum1 / dnum2 << std::endl;
    // Print the integer part of 22 divided by 13
    std::cout << num1 / num2 << std::endl;
    // Print the reminder of 22 divided by 13
    std::cout << num1 % num2 << std::endl;
    return 0;
}