#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

// Write a function that reads all lines of a file
// and writes the read lines to an other file (a.k.a copies the file)
// It should take the filenames as parameters
// It should return a boolean that shows if the copy was successful

bool copyPaster(std::string filePathFrom, std::string filePathTo);

int main() {

    std::ofstream fileForTheExercise;
    fileForTheExercise.open("../fiveminutejournal.txt");

    if(fileForTheExercise.is_open()){
        fileForTheExercise << "The 5 minute journal" << std::endl;
        fileForTheExercise << "is an excellent way to keep" << std::endl;
        fileForTheExercise << "your motivation and spirits high." << std::endl;
        fileForTheExercise.close();
    } else {
        std::cout << "Unable to reach/open file!" << std::endl;
    }
    fileForTheExercise.close();
    std::cout << copyPaster("../fiveminutejournal.txt", "../funfminutejournal.txt") << std::endl;
    return 0;
}
bool copyPaster(std::string filePathFrom, std::string filePathTo){
    bool success = true;
    try{
        std::ifstream fileImCopyingFrom;
        fileImCopyingFrom.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        std::string rememberUs;
        int nrOfLines = 0;
        fileImCopyingFrom.open(filePathFrom);
        std::string line;
        while(getline(fileImCopyingFrom, line)) {
            nrOfLines++;
            for (int i = 0; i < nrOfLines; ++i) {
                rememberUs += line;
            }
        }
        fileImCopyingFrom.close();
        std::ofstream fileImCopyingTo;
        fileImCopyingTo.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        fileImCopyingTo.open(filePathTo);
        fileImCopyingTo<<rememberUs;

    } catch (...){
        success = false;
    }

    return success;
}