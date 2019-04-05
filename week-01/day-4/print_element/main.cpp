#include <iostream>
#include <string>

int printedNumbers();

int array_numbers[4] = {4, 5, 6, 7};

int main(int argc, char *args[]) {

    // - Create an array variable named `numbers`
    //   with the following content: `[4, 5, 6, 7]`
    // - Print all the elements of `numbers`
    printedNumbers();

    return 0;
}

int printedNumbers() {
    for (int i = 0; i < sizeof(array_numbers) / sizeof(array_numbers[0]); i++) {
        std::cout << array_numbers[i] << std::endl;
    }
    return 0;
}
