#include <iostream>

int sumDigits(int longNumber);

int main() {
    std::cout << sumDigits(12345) << std::endl;
    return 0;
}

int sumDigits(int longNumber) {
    if (longNumber == 0) {
        return longNumber;
    } else {
        return (longNumber%10) + sumDigits (longNumber / 10);
    }
}
