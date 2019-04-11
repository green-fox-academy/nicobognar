#include <iostream>

int bunniesAgain(int numberOfBunnies);

int main() {
    std::cout << bunniesAgain(5) << std::endl;
    return 0;
}
int bunniesAgain(int numberOfBunnies){
    if(numberOfBunnies == 0){
        return 0;
    } else if(numberOfBunnies%2 == 1){
        return bunniesAgain(numberOfBunnies - 1) + 2;
    } else if(numberOfBunnies%2 == 0)
        return bunniesAgain(numberOfBunnies - 1) + 3;
}
