#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    // - Create an array variable named `t`
    int array_t[] = {1, 2, 3, 4, 5};
    array_t[2] += 1;
    std::cout << array_t[2] << std::endl;
    //    with the following content: `[1, 2, 3, 4, 5]`
    // - Increment the third element
    // - Print the third element

    return 0;
}