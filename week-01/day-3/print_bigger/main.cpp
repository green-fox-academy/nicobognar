#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that asks for two numbers and prints the bigger one
    int iNumbera;
    int iNumberb;
    std::cout << "Please enter your first number: ";
    std::cin >> iNumbera;
    std::cout << "Thank you, now please enter your second number: ";
    std::cin >> iNumberb;

    if(iNumbera < iNumberb){
        std::cout << iNumberb << " is the bigger one." << std::endl;
    } else if(iNumberb < iNumbera){
        std::cout << iNumbera << " is the bigger one." << std::endl;
    } else if(iNumbera == iNumberb){
        std::cout << "They are equal." << std::endl;
    }

    return 0;
}