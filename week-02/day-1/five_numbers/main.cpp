#include <iostream>

int veryUsefulFunction(int array[], int length);

int main() {
    int arrayEmptyArray[5];
    int *arrayPointer = arrayEmptyArray;
    int length = sizeof(arrayEmptyArray) / sizeof(arrayEmptyArray[0]);
    for (int i = 0; i < 5; ++i) {
        std::cout << "Please enter a number: ";
        std::cin >> arrayEmptyArray[i];
    }
    veryUsefulFunction(arrayPointer, length);

    // Create a program which accepts five integers from the console (given by the user)
    // and store them in an array
    // print out the values of that array using pointers again

    return 0;
}

int veryUsefulFunction(int *ptr, int length) {
    for (int i = 0; i < length; ++i) {
        std::cout << ptr[i] << std::endl;
    }
}