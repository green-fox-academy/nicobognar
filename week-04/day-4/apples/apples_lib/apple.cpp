//
// Created by Nico on 25/04/2019.
//

#include "apple.h"

std::string getApple()
{
    return "apple";
}
int sum(std::vector<int> sumThisUp){
    int sumOfMyVector = 0;
    for (int i = 0; i < sumThisUp.size(); ++i) {
        sumOfMyVector += sumThisUp.at(i);
    }
    return sumOfMyVector;
}