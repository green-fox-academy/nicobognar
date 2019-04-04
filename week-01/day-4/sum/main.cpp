#include <iostream>
#include <string>

int sum(int);
int main(int argc, char* args[]) {

    // Write a function called `sum` that returns the sum of numbers from zero to the given parameter
    // sum()
    std::cout << sum(5) << std::endl; //testing

    return 0;
}
int sum(int n){
    int x = 0;
    for (int i = 0; i <= n; i++){
        x = x + i;
    } return x;
}
