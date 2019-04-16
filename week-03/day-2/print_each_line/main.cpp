#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main () {
    // Write a program that opens a file called "my-file.txt",
    // then prints
    // each line from the file.
    // You will have to create the file, you may use C-programming,
    // although it is not mandatory
    std::ofstream fileForTheExercise;
    fileForTheExercise.open("../my-file.txt");

    if(fileForTheExercise.is_open()){
        fileForTheExercise << "The 5 minute journal" << std::endl;
        fileForTheExercise << "is an excellent way to keep" << std::endl;
        fileForTheExercise << "your motivation and spirits high." << std::endl;
        fileForTheExercise.close();
    } else {
        std::cout << "Unable to reach/open file!" << std::endl;
    }
    try {
        std::ifstream fileForTheExercise;
        fileForTheExercise.open("../my-file.txt");
        std::string line;
        while(getline(fileForTheExercise, line)){
            std::cout << line << std::endl;
        }


    } catch (std::length_error& e){
        std::cout << "Something went wrong." << std::endl;
    }

    return 0;
}