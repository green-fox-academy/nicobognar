#include <iostream>

void veryUsefulFunction(int array[], int length);

int main() {
    int arrayEmptyArray[5];
    int length = sizeof(arrayEmptyArray) / sizeof(arrayEmptyArray[0]);
    for (int i = 0; i < 5; ++i) {
        std::cout << "Please enter a number: ";
        std::cin >> arrayEmptyArray[i];
    }
    veryUsefulFunction(arrayEmptyArray, length);




// Create a program which accepts five integers from the console (given by the user)
// and store them in an array
// print out the memory addresses of the elements in the array

return 0;
}

void veryUsefulFunction(int array[], int length) {
    for (int i = 0; i < length; ++i) {
        std::cout << &array[i] << std::endl;
    }
}