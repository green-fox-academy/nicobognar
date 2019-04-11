#include <iostream>

int greatestCommonDivisor(int first, int second);

int main() {
    std::cout << greatestCommonDivisor(16, 12) << std::endl;
    return 0;
}
int greatestCommonDivisor(int first, int second){
    if(first%second == 0){
        return second;
    } else {
        greatestCommonDivisor(second, first%second);
    }
}
