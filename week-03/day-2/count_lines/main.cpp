#include <iostream>
#include <fstream>
#include <string>

int numberOfLines(std::string fileName);

int main () {
    // Write a function that takes a filename as string,
    // then returns the number of lines the file contains.
    // It should return zero if it can't open the file
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
    //std::ifstream fileForTheFunction;
    //fileForTheFunction.open("../my-file.txt");
    std::cout << numberOfLines("../my-file.txt") << std::endl;
    return 0;
}

int numberOfLines(std::string fileName){
    std::ifstream inputFile;
    int nrOfLines = 0;
    try {
        inputFile.open(fileName);
        std::string line;

        while (getline(inputFile, line)){
            nrOfLines++;
        }
    } catch (...){
        std::cout << "Unexpected error" << std::endl;
    }
    return nrOfLines;
}
