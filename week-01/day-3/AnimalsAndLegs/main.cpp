#include <iostream>

int main(int argc, char* args[]) {

    int nrofchickens;
    int nrofpigs;

    std::cout << "Hello! Please enter how many chickens You currently own: ";
    std::cin >> nrofchickens;
    std::cout << "Thank you. Now, please enter the number of pigs You currently own: ";
    std::cin >> nrofpigs;
    std::cout << "Thank you! To our knowledge, the number of legs your chickens and pigs have altogether add up to: " << (nrofchickens * 2) + (nrofpigs * 4) << " legs." << std::endl;



    // Write a program that asks for two integers
    // The first represents the number of chickens the farmer has
    // The second represents the number of pigs owned by the farmer
    // It should print how many legs all the animals have

    return 0;
}