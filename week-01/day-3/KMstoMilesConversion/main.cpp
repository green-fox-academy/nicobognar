#include <iostream>

int main(int argc, char* args[]) {

    float DistKM;
    std::cout << "Please enter the distance in kilometers: ";
    std::cin >> DistKM;
    std::cout << "The given distance converted to miles is approximately: " << DistKM / 1.609 << "." << std::endl;



    // Write a program that asks for an integer that is a distance in kilometers,
    // then it converts that value to miles and prints it

    return 0;
}