#include <iostream>
#include <fstream>
#include <exception>

int dontDivideByZero(int dThis);

int main() {
    // Create a function that takes a number
    // divides ten with it,
    // and prints the result.
    // It should print "fail" if the parameter is 0
    int userInput;
    std::cout << "Please enter the number you want divided by 10: ";
    std::cin >> userInput;
    dontDivideByZero(userInput);

    return 0;
}
int dontDivideByZero(int dThis){
    try {
        int dThis;
        int byThat = 10;
        if(dThis == 0){
            throw std::string("Do you want to destroy the universe?");
        }
        std::cout << dThis / byThat << std::endl;
    } catch (std::string& e) {
        std::cout << e << std::endl;
    }

}
