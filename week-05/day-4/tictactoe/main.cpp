#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

void ticTacResult(std::string filePathIn);

char ticTacRows(std::vector<std::vector<char>> ticTacMatrix);

char ticTacColumns(std::vector<std::vector<char>> ticTacMatrix);

char ticTacDiagonalA(std::vector<std::vector<char>> ticTacMatrix);

char ticTacDiagonalB(std::vector<std::vector<char>> ticTacMatrix);


int main()
{
    // Write a function that takes a filename as string,
    // open and read it. The file data represents a tic-tac-toe
    // game result. Return 'X'/'O'/'draw' based on which player
    // has winning situation.

    ticTacResult("../win-o.txt");
    // should print O

    ticTacResult("../win-x.txt");
    // should print X

    ticTacResult("../draw.txt");
    // should print draw

    return 0;
}

void ticTacResult(std::string filePathIn)
{
    std::ifstream fileToRead;
    fileToRead.exceptions(std::ifstream::badbit);
    std::vector<std::vector<char>> ticTacToeVector;
    try {
        fileToRead.open(filePathIn);

        std::string line;


        while (std::getline(fileToRead, line)) {
            std::cout << line << std::endl;
            std::vector<char> lineVector;
            for (int i = 0; i < 3; ++i) {
                lineVector.push_back(line.at(i));
            }
            ticTacToeVector.push_back(lineVector);
        }

        fileToRead.close();
    } catch (std::fstream::failure &e) {
        std::cerr << e.what() << std::endl;
    }
    if (ticTacRows(ticTacToeVector) == 'X' || ticTacRows(ticTacToeVector) == 'O') {
        std::cout << ticTacRows(ticTacToeVector);
    } else if (ticTacColumns(ticTacToeVector) == 'X' || ticTacColumns(ticTacToeVector) == 'O') {
        std::cout << ticTacColumns(ticTacToeVector);
    } else if (ticTacDiagonalA(ticTacToeVector) == 'X' || ticTacDiagonalA(ticTacToeVector) == 'O') {
        std::cout << ticTacDiagonalA(ticTacToeVector);
    } else if (ticTacDiagonalB(ticTacToeVector) == 'X' || ticTacDiagonalB(ticTacToeVector) == 'O') {
        std::cout << ticTacDiagonalB(ticTacToeVector);
    } else {
        std::cout << "Draw" << std::endl;
    }
}

char ticTacRows(std::vector<std::vector<char>> ticTacMatrix)
{
    char winner = ' ';
    for (int i = 0; i < ticTacMatrix.size(); ++i) {
        if (ticTacMatrix[i][0] == ticTacMatrix[i][1] && ticTacMatrix[i][1] == ticTacMatrix[i][2]) {
            winner = ticTacMatrix[i][0];
            break;
        }
    }
    return winner;
}

char ticTacColumns(std::vector<std::vector<char>> ticTacMatrix)
{
    char winner = ' ';
    for (int i = 0; i < ticTacMatrix.size(); ++i) {
        if (ticTacMatrix[0][i] == ticTacMatrix[1][i] && ticTacMatrix[1][i] == ticTacMatrix[2][i]) {
            winner = ticTacMatrix[0][i];
            break;
        }
    }
    return winner;
}

char ticTacDiagonalA(std::vector<std::vector<char>> ticTacMatrix)
{
    char winner = ' ';
    if (ticTacMatrix[0][0] == ticTacMatrix[1][1] && ticTacMatrix[1][1] == ticTacMatrix[2][2]) {
        winner = ticTacMatrix[0][0];
    }
    return winner;
}

char ticTacDiagonalB(std::vector<std::vector<char>> ticTacMatrix)
{
    char winner = ' ';
    if (ticTacMatrix[0][2] == ticTacMatrix[1][1] && ticTacMatrix[1][1] == ticTacMatrix[2][0]) {
        winner = ticTacMatrix[1][1];
    }
    return winner;
}





