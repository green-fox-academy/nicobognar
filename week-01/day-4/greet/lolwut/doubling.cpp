#include <iostream>
#include <string>

int doubling(int);
int main(int argc, char* args[]) {

    int baseNum = 123;
    // - Create an integer variable named `baseNum` and assign the value `123` to it

    // - Create a function called `doubling` that doubles it's input parameter and returns with an integer
  std::cout << doubling(baseNum) << std::endl;
    // - Print the result of `doubling(baseNum)`

    return 0;
}
int doubling(int baseNum){
    int result = baseNum * 2;
    return result;
}