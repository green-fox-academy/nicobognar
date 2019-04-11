#include <iostream>

int bunnies(int numberOfBunnies);

int main() {
    std::cout << bunnies(6) << std::endl;
    return 0;
}

int bunnies(int numberOfBunnies){
    if(numberOfBunnies == 0){
        return 0;
    } else{
        return bunnies(numberOfBunnies - 1) + 2;
    }
}
