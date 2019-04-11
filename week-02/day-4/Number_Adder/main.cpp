#include <iostream>

int numberAdder(int n);

int main() {
    std::cout << numberAdder(4) << std::endl;
    return 0;
}

int numberAdder(int n) {
    if (n == 0) {
        return 0;
    } else {
        return n + numberAdder(n - 1);
    }
}
