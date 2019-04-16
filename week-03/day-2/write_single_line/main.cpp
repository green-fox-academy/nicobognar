#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Open a file called "my-file.txt"
    // Write your name in it as a single line
    std::ofstream madeNewFile;
    madeNewFile.exceptions(std::ofstream::failbit | std::ofstream::badbit);
    try {
        madeNewFile.open("../my-file.txt");
        madeNewFile << "Nico Bognar" << std::endl;
    } catch (...){
        std::cout << "Unexpected error" << std::endl;
    }
    madeNewFile.close();

    return 0;
}