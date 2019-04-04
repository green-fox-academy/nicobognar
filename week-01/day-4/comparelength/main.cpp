#include <iostream>
#include <string>

int main(int argc, char* args[]) {
int arrayp1[] = {1, 2, 3};
int arrayp2[] = {4, 5};
if((sizeof(arrayp1) / sizeof(arrayp1[0])) < (sizeof(arrayp2)/sizeof(arrayp2[0])) ){
    std::cout << "This should pop up." << std::endl;
}
    // - Create an array variable named `p1`
    //   with the following content: `[1, 2, 3]`
    // - Create an array variable named `p2`
    //   with the following content: `[4, 5]`
    // - Print if `p2` has more elements than `p1`

    return 0;
}