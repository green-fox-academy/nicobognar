#include <iostream>
#include <string>

int main(int argc, char *args[]) {

    // - Create an array variable named `s`
    int array_s[] = {1, 2, 3, 8, 5, 6};
    array_s[3] = 4;
    std::cout << "The fourth element is: " << array_s[3] << "." << std::endl;
    //   with the following content: `[1, 2, 3, 8, 5, 6]`

    // - Change the 8 to 4
    // - Print the fourth element

    return 0;
}