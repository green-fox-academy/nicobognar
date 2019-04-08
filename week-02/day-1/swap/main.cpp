#include <iostream>

void swap(int *one, int *two);

int main() {
    // Create a function which swaps the values of 'a' and 'b'
    // This time use a void function and pointers

    int a = 10;
    int b = 316;
    swap(&a, &b);
    std::cout << a << "..." << b << std::endl;


    return 0;
}

void swap(int *one, int *two) {
    int three = *one;
    *one = *two;
    *two = three;
}