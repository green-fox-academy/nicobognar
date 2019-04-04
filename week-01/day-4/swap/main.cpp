#include <iostream>
#include <string>
void swap(int, int);
int main(int argc, char* args[]) {
    // Create two integer variables: a=15, b=23
    int a = 15;
    int b = 23;
    std::cout << "CO: " << a << " " << b << std::endl;
    // Create a function named swap that gets the 2 integers as parameters and swaps its values.
    // Print the values before and after the function call and make sure the values are printed in reversed order.

    return 0;
}
// REVISE EVERYTHING. COPYING DOESN'T WORK IN THE LONG RUN
void swap(int& a, int& b){
    b = a + b;
    a = b - a;
    b = b - a;
}