#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    std::string usersname;
    std::cout << "Please enter your name: ";
    std::cin >> usersname;

    // Modify this program to greet user instead of the World!
    // The program should ask for the name of the user
    std::cout << "Hello " << usersname << "!" << std::endl;

    return 0;
}